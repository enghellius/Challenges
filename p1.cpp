#include <iostream>
#include <vector>
#include <dirent.h>

using namespace std;


int main() {
    DIR *dir; 
    struct dirent *diread;
    vector<char *> files;

    int ndirec=0, nfile=0;

    if ((dir = opendir("c:/Users/")) != nullptr) {
        while ((diread = readdir(dir)) != nullptr) {
            if(diread->d_type == DT_DIR){
                ndirec++;
            }
            else if(diread->d_type == DT_REG){
                nfile++;
            }
            printf("%s\n", diread->d_name);
        }
        closedir (dir);
    } else {
        perror ("opendir");
        return EXIT_FAILURE;
    }

    for (auto file : files) cout << file << "| ";
    cout << endl;
    cout<<"Total directory: "<<ndirec<<" Total files: "<<nfile<<endl;
    cout << __cplusplus << endl;
    return EXIT_SUCCESS;
}
