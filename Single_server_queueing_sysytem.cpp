#include<bits/stdc++.h>
#include<stdlib.h>
#include<unistd.h>
#include<windows.h>
using namespace std;

///PBDS Starting.......

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<numeric>
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

///PBDS_SET
///Index of Value - .order_of_key()
///Value at Index - .find_by_order()
//typedef tree<int, nua_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds_set;
//typedef tree<int, null_type, lessorequal<int>, rb_tree_tag,tree_order_statistics_node_update> pbds_multiset;

/// PBDS closing......
#define int long long
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20)
#define endl '\n'
///............Author..................................................................
///........... :: .....................................................................
///...........(  NOBODY  )................................................................
///........... Bangabandhu Sheikh Mujibur Rahman Science and Technlogy University,Gopalganj
///............www.facebook.com/naimur76...................................................
///................durjoyovi76@gmail.com...................................................
///........... ....( N~76 ) ...................................................................
///........... No Copyright .....You can copy and paste my code without any permission.....
/// !!!!!!!!!!!!!!!........................................................................
#define pb push_back
#define esp 0.000000001
#define pi acos(-1)
#define N 1000009
#define ff first
#define ss second
#define all(x) x.begin(),x.end()

/// Code Loading Please wait.............
/// returning to N~76.
/// Loading Finished.....................'
vector<pair<int,int>>vp;
queue<int>q;
map<int,int>mp;
int server=0,now=0,baki=0,ed=0,wait=0,with=0,n;
void call(int n)
{
    for(int i=1; i<=n; i++)
    {
        vp[i]= {rand()%10,rand()%10};
    }
}
vector<int>ans[100],ans2(100);
void man(int n)
{
    //system("cls");
    string s="Busy";
    if(!server){s="Free";baki++;}
    if(server)cout<<"Now time "<<now<<" and server is "<<s<<" With "<<with<<endl;
    else cout<<"Now time "<<now<<" and server is "<<s<<endl;
    int xa=n*5 +30;
    while(xa--)cout<<'-';
    cout<<endl;
    int x=n,xx=n,xxx=n;
    ans[n].push_back(now);
    mp[n]++;
    while(x--)  cout<<"  O  ";

    cout<<"    |   ";
    if(server)cout<<"  O  ";
    cout<<endl;
    while(xx--) cout<<" /|\\ ";
    cout<<" -->|   ";
    if(server)cout<<" /|\\  ";
    cout<<"Service  Center";
    cout<<endl;
    while(xxx--)cout<<" /|\\ ";
      cout<<"    |   ";
    if(server)cout<<" /|\\  ";
    cout<<endl;
    cout<<endl;
   // server=0;
    //Sleep(2);
}
void draw()
{

    man(q.size());
}
void findans()
{
    int nn=n,pos=1,bf=0;
    for(int i=0;; i++)
    {
        now=i;
        if(pos>n&&q.size()==0&&server==0)break;
        ed=i;
        for(int j=pos; j<=n; j++)
        {
            if(vp[j].ff<=i)
            {
                q.push(j);
                pos++;
            }

        }
        if(now>=(bf))
        {

            server=0;
        }
        if(server==0&&q.size()>0)
        {
            server=1;
            with=q.front();
            bf=now+vp[q.front()].ss;
            wait+=(now-vp[q.front()].ff);
            if(bf==now)i--;
            q.pop();
        }
        draw();
        sleep(1);

    }
}
int32_t main()
{

    cin>>n;
    vp.resize(n+1);
    thread td(call,n);
    td.join();
    sort(vp.begin(),vp.end());
    cout<<"Arrival Time------Service Time"<<endl;
    for(int i=1; i<=n; i++)cout<<vp[i].ff<<"                  "<<vp[i].ss<<endl;
    thread thd(findans);
    thd.join();
    int fans=0;
    for(auto c:mp)fans+=(c.ff*c.ss);
  //  cout<<(double)fans/n<<endl;
    cout<<"service started "<<vp[1].ff<<" Service ended "<<ed<<endl;
    double ds=(double)(((baki-1)*100)/ed);
    cout<<"server was idle for "<<ds<<" %"<<endl;
    cout<<"server Utilization "<<100-ds<<" %"<<endl;
    cout<<"average number of customer in Queue "<<(double)(fans/n)<<endl;
    cout<<"Average waiting time "<<(double)wait/n<<endl;

    //cout<<ans[1].size()<<endl;
    return 0;
}


