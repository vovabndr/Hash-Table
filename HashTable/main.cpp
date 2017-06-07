#include <iostream>
#include <vector>
#define N 100
using namespace std;
class HashMap {
private:
    vector< vector<string> > container;
    vector< vector<string> > container_keys;
public:
    HashMap() {
        container.reserve(N);
        container_keys.reserve(N);
    }
    void insert(string key, string value) {
        container[hash_function(key)].push_back(value);
        container_keys[hash_function(key)].push_back(key);
    }
    string get(string key) {
        int hash_value = hash_function(key);
        for (int i = (int)container_keys[hash_value].size() - 1; i >= 0; i--) {
            if (container_keys[hash_value][i] == key)
                return container[hash_value][i];
        }
        return "";
    }
    int hash_function(string real_key) {
        int hash_key = 0;
        for (int i = 0; i < real_key.length(); i++) {
            hash_key += (int) real_key[i];
            if (hash_key > N)   hash_key = 0;
        }
        return hash_key;
    }
    void display_keys(){
        for (int i = 0; i < container_keys[i].size(); i++)
            for (int j = 0; j < container_keys[i][j].size(); j++)
                cout<<container_keys[i][j]<<endl;
        
    }
    void display_container(){
        for (int i = 0; i < container[i].size(); i++)
            for (int j = 0; j < container[i][j].size(); j++)
                cout<<container[i][j]<<endl;
    }
};
int main() {
    HashMap map;
    map.insert("bondar", "vova");
    map.insert("peet","asd");
    map.insert("babch","aaaaaasd");
     
    cout << map.get("bondar")<<endl;
    cout<<map.get("peet")<<endl;
    cout<<map.get("babch")<<endl;
    cout<<endl;
    map.display_keys();
    cout<<endl;
    map.display_keys();
    return 0;
}
