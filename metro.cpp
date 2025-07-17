
#include<bits/stdc++.h>
#include "people.cpp"
#include<unordered_map>
using namespace std;



class Station{
    public:
        string Station_Name;
        int Station_ID;
        vector<Station*> Connected_Stations;
        int Passenger_Count;
        bool isInterchange;
        Station(string Station_Name , int Station_ID){
            this->Station_Name = Station_Name;
            this->Station_ID = Station_ID;
            Passenger_Count = 0;
            isInterchange = false;
        }
        void Add_Connection(Station* station){
            Connected_Stations.push_back(station);
            if(Connected_Stations.size()>=2) isInterchange = true;
        }
        void Update_Passenger_Count(int x){
            Passenger_Count+= x;
        }
        bool isInterchangeStation(){
            return this->isInterchange;
        }
};



class MetroLine{
public:
    vector<Station*> Stations; 
    string Linename;
    MetroLine(string Linename){
        this->Linename = Linename;
    }
    void Add_Station(Station* Station){
        Stations.push_back(Station);
    }
    Station* Get_Station(string name){
        int n = Stations.size();
        for(int i = 0 ; i < n; i++){
            Station* Current_Station = Stations[i];
            if(Current_Station->Station_Name==name) return Current_Station;
        }
        return NULL;
    }
};  




class Graph{
public:
    unordered_map<int ,Station*> stations;
    unordered_map<int,vector<int>> Adjacency_List; 
    void AddStation(Station* station){
        stations[station->Station_ID] = station;
    }
    void AddConnection(Station* Station1 , Station* Station2){
        Adjacency_List[Station1->Station_ID].push_back(Station2->Station_ID);
        Adjacency_List[Station2->Station_ID].push_back(Station1->Station_ID);
    }
    vector<int> GetConnectedStation(Station* station){
        return Adjacency_List[station->Station_ID];
    }
    void GetallGraphs(){
        for(auto x : Adjacency_List){
            cout<<stations[x.first]->Station_Name<<"->";
            for(auto y: x.second){
                cout<<stations[y]->Station_Name<<endl;
            }
            cout<<endl;
        }
    }
    void dfs(Station* Source , string ans , string& realans, Station* Destination  , vector<int>&vis){
        if(Source==Destination){
            if(realans=="" || realans.size()>ans.size()){
                realans = ans;
            }
            return;
        }
        for(int temp_station : Adjacency_List[Source->Station_ID]){
            if(!vis[temp_station]){
                vis[temp_station] = 1;
                dfs(stations[temp_station] , ans+"->"+stations[temp_station]->Station_Name  , realans, Destination , vis);
                vis[temp_station] =0;
            }
        }
        return ;
    }
    string LeastPathFromSourceToDestination(Station* Source , Station* Destination){
        //here we are going to apply a dfs technique 
        string ans = "";
        vector<int> vis(623 , 0);
        vis[Source->Station_ID] = 1;
        dfs(Source , "" , ans , Destination , vis);
        return ans;
    }

};






class Train{
    int TrainID;
    vector<int> route;
    int CurrentStation;
    int NextStation;
    int CurrentPassengerCount;
    Train(int TrainID   , int CurrentPassengerCount , vector<int> route){   
        this->TrainID = TrainID;
        this->CurrentPassengerCount = CurrentPassengerCount;
        this->route = route;
        if(route.size()>0){
            CurrentStation  = 0;
        }
        else{
            CurrentStation = -1;
        }
        if(route.size()>1){
            NextStation = 1;
        }
        else NextStation = -1;
    }
    
    void Board_Passenger(int count){
        CurrentPassengerCount+= count;
    }
};






class MetroSystem{
public:
    Graph* G;
    vector<MetroLine*> Lines;
    vector<Train*> Trains;
    vector<Passenger*> Passengers;
    vector<Employee*> Employees;
    unordered_map<string , Station*> Stations;
    MetroSystem(){
        G = new Graph();
    }
    void AddMetroLine(MetroLine* metroline){
        Lines.push_back(metroline);
    }
    void AddTrain(Train* train){
        Trains.push_back(train);
    }
    void AddPassenger(Passenger* passenger){
        Passengers.push_back(passenger);
    }
    void AddEmployee(Employee* employee){
        Employees.push_back(employee);
    }
    MetroLine* GetMetroLines(string Line){
        for(auto x : Lines){
            if(Line == x->Linename) return x;
        }
        return NULL;
    }
    void AddMetroStation(Station* station){
        string station_name = station->Station_Name;
        if(Stations.find(station_name)==Stations.end()){
            Stations[station_name] = station;
        }
    }
    Station* GetMetroStation(string station_name){
        if(Stations.find(station_name)!=Stations.end()){
            return Stations[station_name];
        }
        else return NULL;
    }
};


