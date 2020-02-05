#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>

using namespace std;

const int ts = 200;

class hashtablentry{
	public:
		int k, v;
	hashtablentry(int k, int v){
		this->k = k;
		this->v =v;
	}
};

class hashtable{
	private:
		hashtablentry **t;
	public:
		hashtable(){
			t = new hashtablentry* [ts];
			for(int i = 0; i < ts; i++){
				t[i] = NULL;
			}
		}
		int hashfunc(int k){
			return k%ts;
		}

		void insert(int k, int v){
			int h = hashfunc(k);
			while(t[h] != NULL && t[h] -> k != k){
				h = hashfunc(h+1);
			}
			if(t[h] != NULL){
				delete t[h];
			}
			t[h] = new hashtablentry(k, v);
		}
		
		void remove(int k){
			int h = hashfunc(k);
			while( t[h] != NULL && t[h] -> k != k){
				if (t[h] -> k == k){
					break;
				}
				h = hashfunc(h+1);
			}
			if(t[h] == NULL){
				cout<<"No element found"<<endl;
				return;
			}
			else{
				delete t[h];
			}
			cout<<"Deleted!"<<endl;
		}
		
		int search(int k){
			int h = hashfunc(k);
			while(t[h] != NULL && t[h] -> k != k){
				h = hashfunc(h+1);
			}
			if( t[h] == NULL){
				cout<<"Not found!"<<endl;
				return -1;
			}
			else{
				return t[h] -> v;
			}
		}
		
		~hashtable(){
			for(int i = 0; i < ts; i++){
				if(t[i] != NULL){
					delete t[i];
					delete []t;
				}
			}
		}


};

//Driver Code
int main(void){
	hashtable hash;
	int k, v, c;
	cout<<"1. insert"<< endl;
	cout<<"2. delete"<< endl;
	cout<<"3. search"<< endl;
	cout<<"4. exit"<< endl;
	while(1){
		cin>>c;
		switch(c){
			case(1):
				cout<<"element to insert"<<endl;
				cin>>v;
				cout<<"input Key"<<endl;
				cin>>k;
				hash.insert(k,v);
			break;
			case(2):
				cout<<"enter Key"<<endl;
				cin>>k;
				hash.remove(k);
			break;
			case(3):
				cout<<"enter Key"<<endl;
				cin>>k;
				if (hash.search(k) == -1){
					cout<<"not Found"<< endl;
				}
				else{	
					cout<<hash.search(k)<<endl;
				}
			break;
			case(4):
				exit(1);
			default:
				cout<<"enter correct option"<<endl;
		}

	}
	return 0;
}
