#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<double> vi_32;
typedef vector<vi_32> vii_32;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second

class Twitter {
public:
  Twitter() {}
  
  void postTweet(int userId, int tweetId) {
    tweets.pb({userId, tweetId});
  }

  vector<int> getNewsFeed(int userId) {
   	int n = tweets.size(), k = 0;
   	auto following_set = following[userId];
   	vector<int> result;
   	for(int i=n-1; i>=0; i--) {
   		if(k==10) break;
   		if(tweets[i].fi == userId) result.pb(tweets[i].se), k++;
   		else if(following_set.find(tweets[i].fi) != following_set.end()) result.pb(tweets[i].se), k++;
   	}
   	return result;
  }

  void follow(int followerId, int followeeId) {
  	following[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    following[followerId].erase(followeeId); 
  }

private:
	vector<pair<int,int>> tweets;
	unordered_map<int, unordered_set<int>> following;
};

int main() {
	Twitter twitter;
	vector<int> news;
	twitter.postTweet(1, 5);
	news = twitter.getNewsFeed(1);
	for(auto n: news) cout << n << " "; cout << endl;
	twitter.follow(1, 2);
	twitter.postTweet(2, 6);
	news = twitter.getNewsFeed(1); for(auto n: news) cout << n << " "; cout << endl;
	twitter.unfollow(1, 2);
	news = twitter.getNewsFeed(1); for(auto n: news) cout << n << " "; cout << endl;
	news = twitter.getNewsFeed(2); for(auto n: news) cout << n << " "; cout << endl;
	return 0;
}