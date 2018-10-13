// Problem found on Geeksforgeeks

//Given a list of tickets, find itinerary in order using the given list.

/* Input:
"Chennai" -> "Banglore"
"Bombay" -> "Delhi"
"Goa"    -> "Chennai"
"Delhi"  -> "Goa"

Output: 
Bombay->Delhi, Delhi->Goa, Goa->Chennai, Chennai->Banglore,*/

// Idea here is to always match a source with a destination

#include <bits/stdc++.h>
using namespace std;

int main(){
	map<string,string> dataSet; 
    dataSet["Chennai"] = "Banglore"; 
    dataSet["Bombay"] = "Delhi"; 
    dataSet["Goa"] = "Chennai"; 
    dataSet["Delhi"] = "Goa";

    // Construct a reverse Map
    map<string,string> reverse;
    for(auto it: dataSet)
    	reverse[it.second]=it.first;

    string start;

    for(auto it: dataSet){
    	if(reverse.find(it.first)==reverse.end()){
    		start = it.first;
    		break;
    	}
    }

    map<string,string>::iterator pt = dataSet.find(start);

    while(pt!=dataSet.end()){
    	cout<<pt->first<<"-->"<<pt->second<<endl;
    	pt=dataSet.find(pt->second);
    }

	return 0;
}