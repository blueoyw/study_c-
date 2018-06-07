#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int number = 6;
int INF = 1000000;

/*
int a[6][6] = {
	{0,2,5,1, INF, INF},
	{2,0,3,2, INF, INF},
	{5,3,0,3, 1, 5},
	{1,2,3,0, 1, INF},
	{INF,INF,1,1, 0, 2},
	{INF,INF,5,INF, 2, 0}
};
*/
vector<pair<int,int> > g[7]; //graph
int d[7]; // cost

void dijkstra(int start) 
{
	d[start] = 0;
	//priority_queue<pair<int,int>> pq; //max heap
	priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > pq; //min heap
	pq.push( make_pair(start, 0 ));

	while( !pq.empty() ) {
		int current = pq.top().first;
		int distance = pq.top().second; //because of max heap
		pq.pop();
		if( d[current] < distance ) continue; //already visit
		for( int i=0; i< g[current].size(); i++ ){
			int next = g[current][i].first;
			int nextDistance = distance + g[current][i].second;
			if( nextDistance < d[next] ) {
				d[next] = nextDistance;
				//pq.push( make_pair(next, -nextDistance ) ); //because of max heap . so make minus
				pq.push( make_pair(next, nextDistance ) ); 
			}
		}
	}
}

int main(void ) {
	for( int i=1; i<=number; i++ ) {
		d[i] = INF;
	}
	g[1].push_back( make_pair(2,2));
	g[1].push_back( make_pair(3,5));
	g[1].push_back( make_pair(4,1));

	g[2].push_back( make_pair(1,2));
	g[2].push_back( make_pair(3,3));
	g[2].push_back( make_pair(4,2));

	g[3].push_back( make_pair(1,5));
	g[3].push_back( make_pair(2,3));
	g[3].push_back( make_pair(4,3));
	g[3].push_back( make_pair(5,1));
	g[3].push_back( make_pair(6,5));

	g[4].push_back( make_pair(1,1));
	g[4].push_back( make_pair(2,2));
	g[4].push_back( make_pair(3,3));
	g[4].push_back( make_pair(5,1));

	g[5].push_back( make_pair(3,1));
	g[5].push_back( make_pair(4,2));
	g[5].push_back( make_pair(6,2));
	
	g[6].push_back( make_pair(3,5));
	g[6].push_back( make_pair(5,2));

	dijkstra(1);

	for( int i=1; i<= number; i++) {
		cout << d[i] << endl;
	}
}
