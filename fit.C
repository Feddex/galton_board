#include <vector>

void fit(){
    std::ifstream in("result.txt");
    in.open();
    std::vector<int> results;
    while(in>>value){
        results.push_back(value);
    }


    TH1F *h = new TH1F("h", "t", result[0], result[1] , result[2]);
    






}