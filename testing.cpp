#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

int main() {
    int input, i=0;
    string text, old, password_0, password_1, password_2, pass, name, age, user, word, word_1;
    vector<string> creds(2);
    vector<string> cp(2);

    ofstream of1; 
    ifstream if1; 
    ifstream if0; 

    cout<<"security system"<<endl;
    cout<<endl;
    cout<<"1. register"<<endl;
    cout<<"2. login"<<endl;
    cout<<"3. change password"<<endl;
    cout<<"4. end program"<<endl;
    cout<<endl;

    do {
        cout<<endl;
        cout<<"enter your choice : "<<flush;
        cin>>input;

        switch(input) {
            case 1:
                cout<<"register"<<endl<<endl;
                cout<<"enter the username : "<<flush;
                cin>>name;
                cout<<"enter the password : "<<flush;
                cin>>password_0;
                cout<<"enter the age : "<<flush;
                cin>>age;

                of1.open("file.txt");
                if(of1.is_open()) {
                    of1<<name<<endl;
                    of1<<password_0<<endl;
                    of1<<age<<endl;
                    of1<<"registration successful"<<endl;
                    of1.close();
                }
            break;

            case 2:
                i=0;
                cout<<"login"<<endl;

                if1.open("file.txt");
                cout<<"enter the username : "<<flush;
                cin>>user;
                cout<<"enter the password : "<<flush;
                cin>>pass;

                if(if1.is_open()) {
                    while(getline(if1, text)) {
                        istringstream iss(text);
                        iss>>word;
                        creds[i]=word;
                        i++;
                        if(i>=2) {
                            i=0;
                            if(creds[0]==user && creds[1]==pass) {
                                cout<<"login successful"<<endl;
                                cout<<"details"<<endl;
                                cout<<"username : "<<creds[0]<<endl;
                                cout<<"password : "<<creds[1]<<endl;
                                cout<<"age : "<<creds[2]<<endl;
                                break;
                            }
                            else {
                                cout<<"incorrect credentials"<<endl;
                                cout<<"press 2 to login"<<endl;
                                cout<<"press 3 to change password"<<endl;
                                break;
                            }
                        }
                    }
                }
                if1.close();
            break;

            case 3:
                i=0;
                cout<<"change password"<<endl;

                if0.open("file.txt");
                cout<<"enter the old password : "<<flush;
                cin>>old;
                if(if0.is_open()) {
                    ofstream of1;
                    of1.open("temp.txt");
                    while(getline(if0, text)) {
                        istringstream iss(text);
                        iss>>word_1;
                        cp[i]=word_1;
                        i++;
                        if(i>=2) {
                            i=0;
                            if(old==cp[1]) {
                                cout<<"enter the new password : "<<flush;
                                cin>>password_1;
                                cout<<"enter the password once again : "<<flush;
                                cin>>password_2;

                                if(password_1==password_2) {
                                    of1<<cp[0]<<endl;
                                    of1<<password_1<<endl;
                                    of1<<cp[2]<<endl;
                                    cout<<"password changed successfully"<<endl;
                                }
                                else {
                                    of1<<text<<endl;
                                    of1<<old;
                                    cout<<"password does not match"<<endl;
                                }
                            }
                            else {
                                cout<<"enter a valid password : "<<flush;
                                break;
                            }
                        }
                    }
                }
            break;

            case 4:
                cout<<"thank you very much"<<endl;
            break;

            default:
                cout<<"enter a valid choice"<<endl;
        }
    }while(input!=4);

    return 0;
}