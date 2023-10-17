#include <vector>
#include <iostream>
#include <memory>

void fit()
{
    std::ifstream infile("result.txt");
    
    std::vector<int> results;
    int value;
    while (infile >> value)
    {
        results.push_back(value);
    }

    int bin_number = results[0];
    double min_extreme = results[1];
    double max_extreme = results[2];

    TH1F *h = new TH1F("h", "t", bin_number, min_extreme, max_extreme);
    for (int bin{1}; bin <= bin_number; ++bin)
    {
        int occurrence = results[1 + bin];
        h->Fill(bin, occurrence);
    }

    TCanvas *canvas = new TCanvas("myCanvas", "My Canvas", 800, 600);
    h->Draw("*");

}