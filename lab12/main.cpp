#include <iostream>
#include <fstream>
#include <string>
#include <sys/types.h>
#include <dirent.h>
#include <vector>

using namespace std;

string PATH = "/Users/max/Downloads/programming/bmstu/Cpp_bmstu/lab12/test/";


string get_ext (const string& st) {
    size_t pos = st.rfind('.');
    if (pos <= 0) return "";
    return st.substr(pos+1, string::npos);
}

int main() {

    DIR *mydir = opendir(PATH.c_str()); // вместо / напиши нужный адрес
    if(!mydir) {
        perror("opendir");
        return -1;
    }
    struct dirent *entry;
    entry = readdir(mydir);
    vector<string> hyperlinks;
    while(entry) {
        string expansion = get_ext(entry->d_name);  // определяем расширение

        if (expansion == "md")
        {
            printf("%s:\n", entry->d_name);
            ifstream f(PATH + entry->d_name);
            string line;

            if(f.is_open())
            {
                int k = 0;
                while (getline(f, line))
                {
                    int start = 0;
                    int end = 0;
                    while (line.find("](", end) != string::npos)
                    {
                        start = line.find("](", end) + 2;
                        end = line.find(')', start);
                        string hyperlink = line.substr(start, end - start);
                        cout << '\t' << hyperlink << endl;
                        hyperlinks.push_back(hyperlink);
                        k++;
                    }
                }
                f.close();
                cout << "\tГиперсссылок в файле: " << k << endl;
            }
        }

        entry = readdir(mydir);
    }
    closedir(mydir);
    cout << endl;

    sort(hyperlinks.begin(), hyperlinks.end());

    ofstream result("../hyperlinks.txt");
    for(auto i: hyperlinks)
        result << i << endl;
}
