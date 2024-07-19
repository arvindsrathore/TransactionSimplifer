#include<bits/stdc++.h>
using namespace std;

const int N = 10;
int adj[N+1][N+1];
map<string,int> alias;
map<int,string> r_alias;
queue<int> q;

void initialize(){
	for(int i=1;i<=N;i++)	q.push(i);
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			adj[i][j] = 0;
		}
	}
}
void check(string name){
	if(alias.find(name)==alias.end()){
		alias[name] = q.front();
		r_alias[q.front()] = name;
		q.pop();
	}
}
void connect_edge(string sender,string contributer,int payment){
	check(sender);
	check(contributer);
	
	int sender_no = alias[sender];
	int contributer_no = alias[contributer];
	adj[sender_no][contributer_no] -= (payment);
	adj[contributer_no][sender_no] += (payment);
}

void disconnect_edge(string sender,string receiver,int payment){
	check(sender);
	check(receiver);
	
	int sender_no = alias[sender];
	int receiver_no = alias[receiver];
	adj[sender_no][receiver_no] -= (payment);
	adj[receiver_no][sender_no] += (payment);
}

vector<char> color;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v) {
    color[v] = 1;
    for(int i=1;i<=N;i++){
    	if(adj[v][i]>0){
    		int u = i;
	        if (color[u] == 0) {
	            parent[u] = v;
	            if (dfs(u))
	                return true;
	        } else if (color[u] == 1) {
	            cycle_end = v;
	            cycle_start = u;
	            return true;
	        }
	    }
    }
    color[v] = 2;
    return false;
}

vector<int> find_cycle() {
    color.assign(N, 0);
    parent.assign(N, -1);
    cycle_start = -1;

    for (int v = 0; v < N; v++) {
        if (color[v] == 0 && dfs(v))
            break;
    }

    if (cycle_start == -1) {
        cout << "Acyclic" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

		vector<int> ans;
        // cout << "Cycle found: ";
        for (int v : cycle)	ans.push_back(v);
            // cout << v << " ";
        // cout << endl;
        return ans;
    }
}
void relax(){
	vector<int> ans = find_cycle();
	int mn = 1000000000;
	int l=ans.size();
	cout<<"Cycle : ";
	for(auto x:ans)	cout<<x<<" ";
	cout<<"\n";
	for(int i=0;i<l-1;i++){
		int u = ans[i];
		int v = ans[i+1];
		mn = min(mn,adj[u][v]);
	}
	for(int i=0;i<l-1;i++){
		int u = ans[i];
		int v = ans[i+1];
		cout<<u<<" "<<v<<" "<<adj[u][v]<<"\n";
		adj[u][v]-=mn;
		adj[v][u]+=mn;
	}
}
int main(){
	initialize();
	while(1){
		cout<<"1: Add Transaction\n";
		cout<<"2: Check Expense\n";
		cout<<"3: Make Payment\n";
		cout<<"4: Relax payments\n";
		cout<<"5. Exit\n";
		cout<<"Choose one : ";
		int choice;cin>>choice;
		cout<<"\n";
		if(choice==1){
			cout<<"Payer Name : ";string sender;cin>>sender;
			cout<<"Number of contributers : ";int friends;cin>>friends;
			for(int count=0;count<friends;count++){
				cout<<"Contributer Name : ";string contributer;cin>>contributer;
				int payment;cin>>payment;
				connect_edge(sender,contributer,payment);
			}		
		}
		else if(choice==2){
			cout<<"Transctions : \n";
			for(int i=1;i<=N;i++){
				for(int j=1;j<=N;j++){
					string one = r_alias[i];
					string two = r_alias[j];
					if(adj[i][j]>0)
					cout<<one<<" needs to pay "<<two<<" Rs "<<adj[i][j]<<".\n";
				}
			}
		}
		else if(choice == 3){
			cout<<"Sender Name : ";string sender;cin>>sender;
			cout<<"Number of receivers : ";int friends;cin>>friends;
			for(int count=0;count<friends;count++){
				cout<<"Receiver Name : ";string receiver;cin>>receiver;
				int payment;cin>>payment;
				disconnect_edge(sender,receiver,payment);
			}
		}
		else if(choice == 4){
			relax();
			
		}
		else{
			break;
		}
	}
}