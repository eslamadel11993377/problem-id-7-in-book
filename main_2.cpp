#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ifstream file;
    file.open("d.txt");
    int gun_time1=0,gun_time2=0,gun_time3=0,id,sensor=0,player_id=0,h=0,m=0,s=0,alltime=0,c=0,player_id_place=0;
    char comma1,comma2;
    vector<int>time;
    cin>>id;
    file>>gun_time1>>gun_time2>>gun_time3;
    while(file>>sensor>>comma1>>player_id>>comma2>>h>>m>>s){
        if (id==player_id){
            time.push_back(h);
            time.push_back(m);
            time.push_back(s);
        }
        if(sensor==2){
                c++;
            if(player_id==id)
                player_id_place=c;
        }
    }

alltime=((time[6]-time[0])*60)+abs(time[7]-time[1])+abs((time[8]-time[2])/60.0);
if(time[4]<time[1])time[3]--;
if(time[7]<time[4])time[6]--;

cout<<"pace between sensor 0 and 1 = "<<(((time[3]-time[0])*60)+abs(time[4]-time[1])+abs((time[5]-time[2])/60.0))/7.0<<endl;
cout<<"pace between sensor 1 and 2 = "<<(((time[6]-time[3])*60)+abs(time[7]-time[4])+abs((time[8]-time[5])/60.0))/(13.1-7.0)<<endl;
cout<<"all time of the race = "<<alltime<<endl;
cout<<"all race pace = "<<(alltime/13.1)<<endl;
cout<<"player last place: "<<player_id_place<<endl;

}
