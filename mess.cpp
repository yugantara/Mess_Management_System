#include<iostream>
#include<string>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<windows.h>
#include<unistd.h>
using namespace std;

class employee{
    private:

        char name[30];
        char id[5];
        char address[10];
        char startfrom[10];
        char upto[10];
        char paid[10];

        void waitForEnter(void){
            cout<<"\n\n\n Press enter to go back \n\n";
            cin.get();
            cin.get();
        }

        // Functions to perform desired actions
        void listEmployees(void){ //To list total employees with Name, Id and Designation
            system("cls");
            FILE *file;
            file= fopen("data.txt", "r");

            cout<<"\n\t\tList of Employees\n";
            cout<<"\n--------------------------------------------------------------------------------------------------------";
            cout<<"\n NAME        |     ID     |     ADDRESS     |   STARTFROM     |            UPTO         |         PAID\n";
            cout<<"----------------------------------------------------------------------------------------------------------";
            while(fscanf(file, "%s %s %s %s %s %s ", &name[0], &id[0] , &address[0], &startfrom[0], &upto[0],&paid[0])!= EOF)
            cout<<"\n"<<name<<"\t\t"<<id<<"\t\t"<<address<<"\t\t"<<startfrom<<"\t\t"<<upto<<"\t\t"<<paid;
            fclose(file);
            waitForEnter();
        }

        void showDetails(void){ //Displays all details according to Employee's id
            system("cls");
            FILE *file;
            char checkId[5];
            cout<<"\n\nEnter Employee ID: ";
            cin>>checkId;
            file= fopen("data.txt", "r");
            while(fscanf(file, "%s %s %s %s %s  %s ", &name[0], &id[0] , &address[0], &startfrom[0], &upto[0],   &paid[0])!=EOF)
                if(strcmp(checkId,id)==0){
                	cout<<"\n---------------------";
                    cout<<"\nName: "<<name;
                    cout<<"\n---------------------";
                    cout<<"\nId: "<<id;
                    cout<<"\n---------------------";
                    cout<<"\nAddress: "<<address;
                    cout<<"\n---------------------";
                    cout<<"\nStartfrom: "<<startfrom;
                    cout<<"\n---------------------";
                    cout<<"\nUpto: "<<upto;
                    cout<<"\n---------------------";
                    cout<<"\nPaid: "<<paid;
                    cout<<"\n---------------------";
                }
            fclose(file);
            waitForEnter();
        }

        void editExisting(void){ //edits Designation and CTC of an employee
            system("cls");
            char checkId[5];
            cout<<"\nEnter employee id: ";
            cin>>checkId;
            char newAddress[10];
            cout<<"\n-----------------------------";
            cout<<"\nEnter new address: ";
            cin>>newAddress;
            char newStartfrom[10];
            cout<<"\n-----------------------------";
            cout<<"\nEnter Startfrom: ";
            cin>>newStartfrom;
            char newUpto[10];
            cout<<"\n-----------------------------";
            cout<<"\nEnter DATE Upto: ";
            cin>>newUpto;
            char newPaid[10];
            cout<<"\n-----------------------------";
            cout<<"\nEnter Paid: ";
            cin>>newPaid;

            FILE *file, *tempfile;
            file= fopen("data.txt", "r");
            tempfile= fopen("temp.txt", "w");
            while(fscanf(file, "%s %s %s %s %s  %s ", &name[0], &id[0] , &address[0],&startfrom[0], &upto[0],  &paid[0])!=EOF){
                if(strcmp(checkId, id)==0)
                    fprintf(tempfile, "%s %s %s %s %s  %s  \n", name, id, newAddress, startfrom, upto,   paid );
                else
                    fprintf(tempfile, "%s %s %s %s %s  %s   \n", name, id, address, startfrom, upto,   paid );
            }
            fclose(file);
            fclose(tempfile);
            int isRemoved= remove("data.txt");
            int isRenamed= rename("temp.txt", "data.txt");
            waitForEnter();
        }

        void addNewEmployee(void){ //adding records
            system("cls");
            cout<<"\n----------------------------------------";
            cout<<"\n Enter First Name of Member: ";
            cin>>name;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Member ID: ";
            cin>>id;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Address: ";
            cin>>address;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Date (Startfrom): ";
            cin>>startfrom;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Date (Upto): ";
            cin>>upto;

            cout<<"\n----------------------------------------";
            cout<<"\n Enter Amount Paid: ";
            cin>>paid;
            cout<<"\n----------------------------------------";

            char ch;
            cout<<"\nEnter 'y' to save above information\n";
            cin>>ch;
            if(ch=='y'){
                FILE  *file;
                file= fopen("data.txt","a");
                fprintf(file, "%s %s %s %s %s   %s \n", name, id, address, startfrom, upto,  paid );
                fclose(file);
                cout<<"\nNew Employee has been added to database\n";
            }
            else
                addNewEmployee();
            waitForEnter();
        }

        void deleteEmployeeDetails(void){ //removing records
            system("cls");
            char checkId[5];
            cout<<"\n----------------------------------";
            cout<<"\nEnter Employee Id To Remove: ";
            cin>>checkId;
            char ch;
            cout<<"----------------------------------";
            cout<<"\n\n\n\n\nCONFIRMATION\nEnter 'y' To Confirm Deletion \n";
            cin>>ch;
            if(ch=='y'){
                FILE *file, *tempfile;
                file= fopen("data.txt", "r");
                tempfile= fopen("temp.txt", "w");
                while(fscanf(file, "%s %s %s %s %s %s  ", &name[0], &id[0] , &address[0], startfrom[0], upto[0],   &paid[0])!=EOF)
                    if(strcmp(checkId, id)!=0)
                        fprintf(tempfile, "%s %s %s %s %s   %s \n", name, id, address, startfrom, upto,   paid );
                fclose(file);
                fclose(tempfile);
                int isRemoved= remove("data.txt");
                int isRenamed= rename("temp.txt", "data.txt");
                cout<<"\nRemoved Successfully\n";
                waitForEnter();
            }
            else
                deleteEmployeeDetails();
        }


    public:
        // Function to serve as end point
        void options(void){ //menu
        int login(); //login declaration
                login();//login screen
            while(true){
                system("cls");

                // Options to choose an action
                cout<<"\n\t\t\t>>>>>>>>>  MESS MANAGEMENT SYSTEM  <<<<<<<<<";
                cout<<"\n";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   1:   To View List of Members";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   2:   To View Members Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   3:   To Modify Existing Members Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   4:   To Add New Members Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   5:   To Remove an Members Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   0:   To Exit     ";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\n\t\t\t   Please Enter Your Choice: ";

                // Taking the action input
                int choice;
                cin>>choice;
                // Calling relevant function as per choice
                switch (choice) {
                    case 0:
                    	system("CLS");
                        cout<<"\n\nMESS MANAGEMENT SYSTEM \n\n ";
                        Sleep(10);
                        return;
                    case 1:
                        listEmployees();
                        break;
                    case 2:
                        showDetails();
                        break;
                    case 3:
                        editExisting();
                        break;
                    case 4:
                        addNewEmployee();
                        break;
                    case 5:
                        deleteEmployeeDetails();
                        break;
                    default:
                        cout<<"\n Sorry! I don't understand that! \n";
                        break;
                }

            }
        }

};

int main(){
    // Call the options function
    employee e;
    e.options();
    return 0;
}

int login(){ //login procedure
   string pass ="";
   char ch;
   cout <<"\n\n\n\n\t\t\t\t\tMESS MANAGEMENT SYSTEM";
   cout <<"\n\n\n\n\n\t\t\t\t\tEnter Your Password :";
   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "pass"){
   	cout<<"\n\n\n\t\t\t\t\tLOADING \n\t\t\t\t\t";
   	for(int a=1;a<8;a++) // Change 'a<?' to how many * you want
	{
		Sleep(500);
		cout << "...";
	}
      cout << "\n\n\n\t\t\t\t\tAccess Granted!! \n\n\n";

      system("PAUSE");
      system("CLS");
   }else{
      cout << "\nAccess Aborted...\n";
      login();
   }
}
