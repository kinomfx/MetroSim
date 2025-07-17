#include<bits/stdc++.h>
#include "metro.cpp"
#include<fstream>
using namespace std;
void InitializeMetroLines(MetroSystem* metro, vector<string> lineNames) {
    for (const string& name : lineNames) {
        metro->AddMetroLine(new MetroLine(name));
    }
}
void InitializeStations(MetroLine* Line , vector<pair<string, int>> station , MetroSystem* Delhi){
    for(auto x : station){
        string name = x.first;
        int id = x.second;
        if(Delhi->Stations.find(name)==Delhi->Stations.end()){
            Station* station = new Station(name , id);
            Line->Add_Station(station);
            Delhi->Stations[name] = station;
            Delhi->G->AddStation(station);

        }
        else{
            Station* station = Delhi->Stations[name]; 
            Line->Add_Station(station);
        }
        
    }
    return ;
}
void InitializeMetroSystem(MetroSystem* Delhi){
    fstream MyReadFile("C:/Users/monik rayu/machine_learning/metro_project/MetroStations.txt");
    string Line ;
    if (!MyReadFile) {
        cerr << "Error: Unable to open file!" << endl;
        return;
    }
    string metroline="";
    vector<pair<string , int>> vec;
    while(getline(MyReadFile , Line)){
        if(Line[0]=='#'){
            if(metroline!=""){
                MetroLine* metroLine  = Delhi->GetMetroLines(metroline);
                if(metroLine!=NULL) InitializeStations(metroLine , vec , Delhi);
            }
            vec.clear();
            metroline = Line.substr(2 , Line.size()-2);
        }
        else{
            int n = Line.size();
            string Station ="";
            int i = 0;
            while(Line[i]!=',') Station+=Line[i++];
            i++;
            string id ="";
            int idx = 0;
            while(i<n){
                id+=Line[i++];
            }
            idx = stoi(id);
            /*for(int i = id.size()-1 ; i>=0 ;i--){
                idx+= id[i]*increment;
                increment*=10;
            }*/
            //cout<<idx<<endl;
            vec.push_back({Station , idx});
        }
    }
    MyReadFile.close();
}
void InitializeConnectedStations(MetroSystem* Delhi){
    vector<string> temp = {"Yellow" , "Blue" , "Pink" , "Green" , "Red" , "Magenta"};
    for(int j = 0 ; j <6; j++){
        MetroLine* line = Delhi->GetMetroLines(temp[j]);
        int n = line->Stations.size();
        for(int i = 0 ; i < n ; i++){
            Station* station = line->Stations[i];
            Delhi->AddMetroStation(station);
            Station* temp2 ;
            if(i+1<n){
                temp2 = line->Stations[i+1];
                station->Connected_Stations.push_back(temp2);
                Delhi->G->AddConnection(station , temp2);
            }
        }
    }
    
}
int main(){
    MetroSystem* Delhi = new MetroSystem();
    Graph* Delhi_Graph = Delhi->G;
    InitializeMetroLines(Delhi , {"Yellow" , "Blue" , "Pink" , "Green" , "Red" , "Magenta"});
    InitializeMetroSystem(Delhi);
    InitializeConnectedStations(Delhi);
    Station* Saket = Delhi->GetMetroStation("Sikandarpur");
    Station* Lajpat = Delhi->GetMetroStation("Welcome");
    cout<<Saket->Station_ID<<endl;
    cout<<Delhi_Graph->LeastPathFromSourceToDestination(Saket , Lajpat);
    return 0;
}