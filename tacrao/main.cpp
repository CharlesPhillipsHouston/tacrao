//  main.cpp 12 sep 2022
//  tacrao - this is a practice input, output program
//
//  Created by Charles Phillips on 8/16/22.
//  Copyright © 2022 charles. All rights reserved
// this version works and creates output
// now reading .csv file and data is read better
// this reads the first line 9 times grrr finds first two fields

#include <iostream>
#include <fstream>
#include <string>
#include <cstring> // I hope to not need C strings

using namespace std;

string fair_name = "a"; // first field is fair name, give it an intial value
string fair_date = "b"; // second field
string fair_time = "c"; // third field
string fair_location = "d";
string fair_city = "not Houston";
string fair_county = "not Harris";
string primary_contact_name = "not Charles";

string line, *p;  // need this???

int main(int argc, const char * argv[])
{
      string homeDir = getenv("HOME");  // detects if it is on Mini or laptop
    
    string ifname = homeDir + "/Desktop/common_files/tacroa_data_big.csv";
    // this works better when you go to the .csv file
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
     
     while (i < 9)  //
     {
     //    string line;  //  create line
         getline(fin, line);
         
   //      string fair_name = line.substr(); // read fair name at pos this reads the entire file!!
         
         string fair_name = line.substr(0,9); // just the first ten char first char 0 then 9 more
         
    size_t pos = line.find(","); // first "position" find a comma in line
         // pos = position??
         
    string fair_date = line.substr (pos +1,9); // get second field nine char
 
  // pos and pos1 find the same place
         
     size_t pos1 = line.find(","); // find another comma, second field
                 
    string fair_time = line.substr (pos1 +1,9); // at pos(1)??
         
  //  size_t pos2 = line.find(","); // find another comma, second field
                 
 // string fair_location = line.substr (pos2); // at pos(1)??
    
         ++i;  // increment i to stop while loop
    
     //    const char *p = line.c_str();
     //    p = strtok(line, ",");
         
 //    const char *s = line.c_str(); // throw in some C here this does work
 //    sscanf(s, "%s" "%s" "%s", &fair_name, &fair_date, &fair_time);
    
    //     fout << "line: " << line << endl; // just output the entire line to see what we got
    // this works great!
         
    fout << "Name: " << fair_name << '\n' << "Date: " << fair_date << "\n" << "Time: " << fair_time << "\n" << endl;
         
         // << "Fair Location: " << "\n" << fair_location << endl;
         
     //    fout << "Name " << fair_name << '\n' << endl;
         
         
         // " Date " << fair_date << '\n' << " Time " << fair_time << " Location " << fair_location << endl; // output
    
     }  // end of while loop
    
    fin.close(); // close input stream
    fout.close(); // close output stream
    
    return 0;
}
