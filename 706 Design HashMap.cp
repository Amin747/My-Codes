class MyHashMap {
public:
    vector<pair<int, int>>vec;
    /** Initialize your data structure here. */
    MyHashMap() {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        for (int i=0; i<vec.size(); i++){
            if (vec[i].first==key){
                vec[i].second = value;
                return;
            }
        }
        pair<int,int>p = {key, value};
        vec.push_back(p);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        for (int i=0; i<vec.size(); i++){
            if (vec[i].first == key){
                return vec[i].second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        for (int i=0; i<vec.size(); i++){
            if (vec[i].first == key){
                vec.erase(vec.begin() + i);
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
