class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string>ans;
        vector<string>items;
        map<string, int>m;
        for(int i=0; i<cpdomains.size(); i++){
            int j=0;
            string count;
            while (cpdomains[i][j]!=' '){
                count+=cpdomains[i][j];
                j++;
            }
            int c = stoi(count);
            string temp;
            j = cpdomains[i].size()-1;
            while (j >=0){
                bool found = false;
                if (cpdomains[i][j]!= '.' && cpdomains[i][j]!= ' '){
                    temp.insert(temp.begin(), cpdomains[i][j]);
                    j--;
                }
                else if (cpdomains[i][j]=='.'){
                    m[temp]+=c;
                    for(int i=0; i<items.size(); i++){
                        if (items[i]==temp){
                            found = true;
                        }
                    }
                    if(found == false) {
                        items.push_back(temp);
                    }
                    temp.insert(temp.begin(), '.');
                    j--;
                }
                else if (cpdomains[i][j]==' '){
                    m[temp]+=c;
                    for(int i=0; i<items.size(); i++){
                        if (items[i]==temp){
                            found = true;
                        }
                    }
                    if(found == false) {
                        items.push_back(temp);
                    }
                    temp.insert(temp.begin(), '.');
                    break;
                }
            }
        }
        for (int i=0; i<items.size(); i++){
            ans.push_back(to_string(m[items[i]]) + ' ' + items[i]);
        }
        return ans;
    }
};
