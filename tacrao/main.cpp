//  28 aug 2023
//  tacrao - this is a practice input, output program
//
//  Created by Charles Phillips on 8/16/22.
//  Copyright 24 aug 2023 charles. All rights reserved
//  heavily modified by mike marston!!!

#include <iostream>
#include <fstream>
#include <string>
#include <cstring> // I hope to not need C strings

using namespace std;

string ExtractNextCsv(string searchString, size_t &startPos)
{
        //probably should verify that startPos is positive and less than length of searchString
        string tempString;
        size_t nextPos = searchString.find(",", startPos); // find a comma in line
        if(nextPos == string::npos) // end of line reached
        {
          tempString = searchString.substr(startPos);
          startPos = nextPos;
        }
        else
        {
          size_t length = nextPos - startPos;
          tempString = searchString.substr(startPos, length );  //extract string from start of string up but not including ,
          startPos = nextPos+1; //advance startPos past this occurence
        }

        return tempString;

}

string fair_name = "a"; // first field is fair name, give it an initial value
string fair_date = "b"; // second field
string fair_time = "c"; // third field

string line;  // need this???

int main(int argc, const char * argv[])
{
     
      string homeDir = getenv("HOME");  // detects if it is on Mini or laptop
    
    string ifname = homeDir + "/Desktop/common_files/tacroa_data.txt";
    
      string ofname = homeDir + "/Desktop/common_files/tacroa_output.txt";
      
      ifstream fin(ifname);
      
    ofstream fout(ofname);

    if (! fin)
     {
       cerr << "Error opening input file " << ifname << endl;
       return 1;
     }
    
   /*
     ofstream fout(outFilePath);
      
      if (!stringout)
      {
        cerr << "Error opening output file " << outFilePath << endl;
        return 1;
      }
      
        ifstream targetFile(homeDir + "/Desktop/common_files/satellite1.txt");
    */
    
    // fin.getline(fair_name, 20); //get a line of text from fin, call the first field a and it has 20 chars
    
     int i = 0; // set up the way to count in the while loop
     
     while (i < 4)
     {
     //    string line;  //  create line
         getline(fin, line);
         fout <<"Line: "  << line << endl;
         
        size_t pos = line.find(","); // find a comma in line
        string fair_name = line.substr(0, pos);  //extract string from start of string up but not including ,
                      
        size_t pos1 = line.find(",", pos+1); // find the next comma in line (search starts at pos+1)
        string fair_date = line.substr (pos+1, pos1-(pos+1)); //extract starting 1st char after last , & up to but not including , just found
            
        size_t pos2 = line.find(",", pos1+1); // find next comma in line
        string fair_time = line.substr (pos1+1, pos2-(pos1+1));
         
         ++i;  // increment i to stop while loop
    
     //    const char *p = line.c_str();
     //    p = strtok(line, ",");
         
 //    const char *s = line.c_str(); // throw in some C here
 //    sscanf(s, "%s" "%s" "%s", &fair_name, &fair_date, &fair_time);
    
    //     fout << "line: " << line << endl; // just output the entire line to see what we got
    // this works great!
         
  fout << "Name " << fair_name << "\n" << " Fair Date " << fair_date << "\n" << " Fair Time " << fair_time << "\n" << endl;
         
      size_t startPos = 0;
      int counter = 1;
      while(startPos != string::npos)
      {
        string nextString = ExtractNextCsv(line, startPos); //note startPos passed by reference so it can be updated!!!
        fout << "Var " << counter << " = " << nextString << std::endl;
        counter++;
      }
    }  // end of while loop
    
    fin.close();
    fout.close();
    
    return 0;
}
