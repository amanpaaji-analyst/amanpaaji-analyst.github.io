//---------------|| Aman Paaji 2nd Project ||---------------
#include<iostream>
#include<fstream>
#include<cstdio>
#include<iomanip>
using namespace std;
class BMS {
    // ⬇️ All Files
    fstream file,tempFile;
    // ⬇️ Personal Details Variable
    string C_FullName,C_FatherName,C_DOB,C_Password,C_Email,C_Mobile,C_Aadhar;
    // ⬇️ Bank Details Variable
    string C_AccountNumber,C_Branch,C_IFSC;
    int C_Balance=0;
    // Temporary Searching Variable
    string searchAcc,searchPass,searchDOB,searchMob,searchAadhar,searchBal,recieverAcc,temp;
    // ⬇️ All Member Functions
public:
    void createAccount();
    void loginAccount();
    void forgotPassword();
    void depositMoney();
    void withdrawMoney();
    void balanceCheck();
    void transferMoney();
    void deleteAccount();
    void checkAccount();
    void exitSystem();
};
void BMS :: createAccount() {
    cout<<"----------|| Create Account ||----------"<<endl;
    int account=261000;
    file.open("Bank_Management_File.txt",ios::in);
    while(getline(file,temp,'\t')) {
        try {
            account = stoi(temp);
        }
        catch(...) {
            file.close();
            cout<<"file Data Corrupted..";
            return ;
        }
        for(int i=0; i<=9; i++)
            getline(file,temp,(i==9)?'\n':'\t');
    }
    file.close();
    C_AccountNumber=to_string(account+1);
    cout<<"Enter Your Full Name :: ";
    getline(cin,C_FullName);
    cout<<"Enter Your Father Name :: ";
    getline(cin,C_FatherName);
    cout<<"Enter Your Date of Birth (dd-mm-yy) :: ";
    getline(cin,C_DOB);
    cout<<"Enter Your Mobile Number :: ";
    getline(cin,C_Mobile);
    cout<<"Enter Your Aadhar Number :: ";
    getline(cin,C_Aadhar);
    cout<<"Enter Your Email Id :: ";
    getline(cin,C_Email);
    cout<<"Enter Your Branch :: ";
    getline(cin,C_Branch);
    cout<<"Enter Your IFSC Code:: ";
    getline(cin,C_IFSC);
    cout<<"Now Create your Strong Password :: ";
    getline(cin,C_Password);
    file.open("Bank_Management_File.txt",ios::app);
    file<<C_AccountNumber<<'\t'
        <<C_FullName<<'\t'
        <<C_FatherName<<'\t'
        <<C_DOB<<'\t'
        <<C_Mobile<<'\t'
        <<C_Aadhar<<'\t'
        <<C_Email<<'\t'
        <<C_Branch<<'\t'
        <<C_IFSC<<'\t'
        <<C_Balance<<'\t'
        <<C_Password<<endl;
    file.close();
    cout<<"\nYour Account is Successfully Created"<<endl;
    cout<<"Your Account Number is : "<<C_AccountNumber;
}
void BMS :: loginAccount() {
    cout<<"----------|| Login Account ||----------"<<endl;
    cout<<"Enter Your Account Number :: ";
    getline(cin,searchAcc);
    cout<<"Enter Your Password :: ";
    getline(cin,searchPass);
    file.open("Bank_Management_File.txt",ios::in);
    if(!file) {
        cout<<"File Not Found";
        return ;
    }
    while(getline(file,C_AccountNumber,'\t')) {
        for(int i=0; i<9; i++)
            getline(file,temp,'\t');
        getline(file,C_Password,'\n');
        if(searchAcc==C_AccountNumber) {
            if(searchPass==C_Password) {
                file.close();
                cout<<"\nYour Account Logged in Successfully";
                return;
            }
            else {
                file.close();
                cout<<"\nInvalid Password\nTry Again";
                return;
            }
        }
    }
    file.close();
    cout<<"Account NOT Found";
}
void BMS :: forgotPassword() {
    cout<<"----------|| Forgot Password ||----------"<<endl;
    cout<<"Enter Your Account Number :: ";
    getline(cin,searchAcc);
    cout<<"Enter Your Aadhar Number :: ";
    getline(cin,searchAadhar);
    cout<<"Enter Your Mobile Number :: ";
    getline(cin,searchMob);
    cout<<"Enter Your Date of Birth (dd-mm-yy) :: ";
    getline(cin,searchDOB);
    file.open("Bank_Management_File.txt",ios::in);
    if(!file) {
        cout<<"\nFile Not Found";
        return;
    }
    while(getline(file,C_AccountNumber,'\t')) {
        getline(file,temp,'\t');
        getline(file,temp,'\t');
        getline(file,C_DOB,'\t');
        getline(file,C_Mobile,'\t');
        getline(file,C_Aadhar,'\t');
        getline(file,temp,'\t');
        getline(file,temp,'\t');
        getline(file,temp,'\t');
        getline(file,searchBal,'\t');
        getline(file,C_Password,'\n');
        if(searchAcc==C_AccountNumber) {
            if(searchAadhar==C_Aadhar) {
                if(searchMob==C_Mobile) {
                    if(searchDOB==C_DOB) {
                        file.close();
                        cout<<"\nYour Account is Successfully Forgot"<<endl;
                        cout<<"Your Account Password :: "<<C_Password;
                        return;
                    }
                    else {
                        file.close();
                        cout<<"\nInvalid DOB\nTry Again";
                        return;
                    }
                }
                else {
                    file.close();
                    cout<<"\nInvalid Mobile Number\nTry Again";
                    return;
                }
            }
            else {
                file.close();
                cout<<"\nInvalid Aadhar Number\nTry Again";
                return;
            }
        }
    }
    file.close();
    cout<<"\nAccount NOT Found\nTry Again";
}
void BMS :: depositMoney() {
    bool found=false;
    cout<<"----------|| Deposit ||----------"<<endl;
    cout<<"Enter Your Account Number :: ";
    getline(cin,searchAcc);
    cout<<"Enter Your Password :: ";
    getline(cin,searchPass);
    cout<<"Enter the Ammount :: ";
    getline(cin,searchBal);
    if(stoi(searchBal)>0) {
        file.open("Bank_Management_File.txt",ios::in);
        tempFile.open("Temporary_File.txt",ios::out);
        if(!file) {
            tempFile.close();
            cout<<"\nFile NOT Found";
            return;
        }
        while(getline(file,C_AccountNumber,'\t')) {
            getline(file,C_FullName,'\t');
            getline(file,C_FatherName,'\t');
            getline(file,C_DOB,'\t');
            getline(file,C_Mobile,'\t');
            getline(file,C_Aadhar,'\t');
            getline(file,C_Email,'\t');
            getline(file,C_Branch,'\t');
            getline(file,C_IFSC,'\t');
            getline(file,temp,'\t');
            C_Balance=stoi(temp);
            getline(file,C_Password,'\n');
            if(searchAcc==C_AccountNumber) {
                if(searchPass==C_Password) {
                    C_Balance+=stoi(searchBal);
                    found=true;
                }
                else {
                    file.close();
                    tempFile.close();
                    remove("Temporary_File.txt");
                    cout<<"\nInvalid Password\nTry Again";
                    return;
                }
            }
            tempFile<<C_AccountNumber<<'\t'
                    <<C_FullName<<'\t'
                    <<C_FatherName<<'\t'
                    <<C_DOB<<'\t'
                    <<C_Mobile<<'\t'
                    <<C_Aadhar<<'\t'
                    <<C_Email<<'\t'
                    <<C_Branch<<'\t'
                    <<C_IFSC<<'\t'
                    <<C_Balance<<'\t'
                    <<C_Password<<endl;
        }
        file.close();
        tempFile.close();
        if(!found) {
            remove("Temporary_File.txt");
            cout<<"\nAccount NOT Found\nTry Again";
            return;
        }
        else {
            remove("Bank_Management_File.txt");
            rename("Temporary_File.txt","Bank_Management_File.txt");
            cout<<"\nMoney is Successfully Deposit Your Account";
            return;
        }
    }
    else {
        cout<<"\nInvalid Ammount\nTry Again";
        return;
    }
}
void BMS :: withdrawMoney() {
    bool found=false;
    cout<<"----------|| Withdraw ||----------"<<endl;
    cout<<"Enter Your Account Number :: ";
    getline(cin,searchAcc);
    cout<<"Enter Your Password :: ";
    getline(cin,searchPass);
    cout<<"Enter the Ammount :: ";
    getline(cin,searchBal);
    if(stoi(searchBal)>0) {
        file.open("Bank_Management_File.txt",ios::in);
        tempFile.open("Temporary_File.txt",ios::out);
        if(!file) {
            tempFile.close();
            cout<<"\nFile NOT Found";
            return;
        }
        while(getline(file,C_AccountNumber,'\t')) {
            getline(file,C_FullName,'\t');
            getline(file,C_FatherName,'\t');
            getline(file,C_DOB,'\t');
            getline(file,C_Mobile,'\t');
            getline(file,C_Aadhar,'\t');
            getline(file,C_Email,'\t');
            getline(file,C_Branch,'\t');
            getline(file,C_IFSC,'\t');
            getline(file,temp,'\t');
            C_Balance=stoi(temp);
            getline(file,C_Password,'\n');
            if(searchAcc==C_AccountNumber) {
                if(searchPass==C_Password) {
                    if(stoi(searchBal)<=C_Balance) {
                        C_Balance-=stoi(searchBal);
                        found=true;
                    }
                    else {
                        file.close();
                        tempFile.close();
                        remove("Temporary_File.txt");
                        cout<<"\nInsufficient Balance\nTry Again";
                        return;
                    }
                }
                else {
                    file.close();
                    tempFile.close();
                    remove("Temporary_File.txt");
                    cout<<"\nInvalid Password\nTry Again";
                    return;
                }
            }
            tempFile<<C_AccountNumber<<'\t'
                    <<C_FullName<<'\t'
                    <<C_FatherName<<'\t'
                    <<C_DOB<<'\t'
                    <<C_Mobile<<'\t'
                    <<C_Aadhar<<'\t'
                    <<C_Email<<'\t'
                    <<C_Branch<<'\t'
                    <<C_IFSC<<'\t'
                    <<C_Balance<<'\t'
                    <<C_Password<<endl;
        }
        file.close();
        tempFile.close();
        if(!found) {
            remove("Temporary_File.txt");
            cout<<"\nAccount NOT Found\nTry Again";
            return;
        }
        else {
            remove("Bank_Management_File.txt");
            rename("Temporary_File.txt","Bank_Management_File.txt");
            cout<<"\nMoney is Successfully Withdraw From Your Account";
            return;
        }
    }
    else {
        cout<<"\nInvalid Ammount\nTry Again";
        return;
    }
}
void BMS :: balanceCheck() {
    cout<<"----------|| Balance Check ||----------"<<endl;
    cout<<"Enter Your Account Number :: ";
    getline(cin,searchAcc);
    cout<<"Enter Your Password :: ";
    getline(cin,searchPass);
    file.open("Bank_Management_File.txt");
    if(!file) {
        cout<<"\nFile NOT Found";
        return;
    }
    while(getline(file,C_AccountNumber,'\t')) {
        for(int i=0; i<8; i++)
            getline(file,temp,'\t');
        getline(file,searchBal,'\t');
        getline(file,C_Password,'\n');
        if(searchAcc==C_AccountNumber) {
            if(searchPass==C_Password) {
                file.close();
                cout<<"\nAccount Found"<<endl;
                cout<<"Your Balance is :: "<<searchBal;
                return;
            }
            else {
                file.close();
                cout<<"\nInvalid Password\nTry Again";
                return;
            }
        }
    }
    file.close();
    cout<<"\nAccount NOT Found\nTry Again";
    return;
}
void BMS :: transferMoney() {
    bool senderFound=false, receiverFound=false;
    cout<<"----------|| Transfer ||----------"<<endl;
    cout<<"Enter Your Account Number :: ";
    getline(cin,searchAcc);
    cout<<"Enter your Account Password :: ";
    getline(cin,searchPass);
    cout<<"Enter the Amount :: ";
    getline(cin,searchBal);
    cout<<"Enter Receiver Account Number :: ";
    getline(cin,recieverAcc);
    if(stoi(searchBal)<=0) {
        cout<<"Invalid Amount\nTry Again";
        return;
    }
    file.open("Bank_Management_File.txt",ios::in);
    tempFile.open("Temporary_File.txt",ios::out);
    if(!file) {
        tempFile.close();
        cout<<"\nFile NOT Found";
        return;
    }
    while(getline(file,C_AccountNumber,'\t')) {
        getline(file,C_FullName,'\t');
        getline(file,C_FatherName,'\t');
        getline(file,C_DOB,'\t');
        getline(file,C_Mobile,'\t');
        getline(file,C_Aadhar,'\t');
        getline(file,C_Email,'\t');
        getline(file,C_Branch,'\t');
        getline(file,C_IFSC,'\t');
        getline(file,temp,'\t');
        C_Balance=stoi(temp);
        getline(file,C_Password,'\n');
        if(searchAcc==C_AccountNumber) {
            if(searchPass!=C_Password) {
                file.close();
                tempFile.close();
                remove("Temporary_File.txt");
                cout<<"\nInvalid Password\nTry Again";
                return;
            }
            if(stoi(searchBal)>C_Balance) {
                file.close();
                tempFile.close();
                remove("Temporary_File.txt");
                cout<<"\nInsufficient Balance\nTry Again";
                return;
            }
            else {
                if(searchAcc!=recieverAcc) {
                    C_Balance-=stoi(searchBal);
                    senderFound=true;
                }
                else {
                    file.close();
                    tempFile.close();
                    remove("Temporary_File.txt");
                    cout<<"\nSender and Receiver Account cannot be the same.\nTry Again";
                    return;
                }
            }
        }
        if(recieverAcc==C_AccountNumber) {
            C_Balance+=stoi(searchBal);
            receiverFound=true;
        }
        tempFile<<C_AccountNumber<<'\t'
                <<C_FullName<<'\t'
                <<C_FatherName<<'\t'
                <<C_DOB<<'\t'
                <<C_Mobile<<'\t'
                <<C_Aadhar<<'\t'
                <<C_Email<<'\t'
                <<C_Branch<<'\t'
                <<C_IFSC<<'\t'
                <<C_Balance<<'\t'
                <<C_Password<<endl;
    }
    file.close();
    tempFile.close();
    if(!senderFound) {
        remove("Temporary_File.txt");
        cout<<"\nSender Account NOT Found\nTry Again";
        return;
    }
    if(!receiverFound) {
        remove("Temporary_File.txt");
        cout<<"\nReceiver Account NOT Found\nTry Again";
        return;
    }
    remove("Bank_Management_File.txt");
    rename("Temporary_File.txt","Bank_Management_File.txt");
    cout<<"\nMoney is Successfully Transfer";
}
void BMS :: deleteAccount() {
    bool delFound=false;
    cout<<"----------|| Delete Account ||----------"<<endl;
    cout<<"Enter Your Account Number :: ";
    getline(cin,searchAcc);
    cout<<"Enter your Account Password :: ";
    getline(cin,searchPass);
    file.open("Bank_Management_File.txt",ios::in);
    tempFile.open("Temporary_File.txt",ios::out);
    if(!file) {
        tempFile.close();
        cout<<"\nFile NOT Found";
        return;
    }
    while(getline(file,C_AccountNumber,'\t')) {
        getline(file,C_FullName,'\t');
        getline(file,C_FatherName,'\t');
        getline(file,C_DOB,'\t');
        getline(file,C_Mobile,'\t');
        getline(file,C_Aadhar,'\t');
        getline(file,C_Email,'\t');
        getline(file,C_Branch,'\t');
        getline(file,C_IFSC,'\t');
        getline(file,temp,'\t');
        C_Balance=stoi(temp);
        getline(file,C_Password,'\n');
        if(searchAcc==C_AccountNumber) {
            if(searchPass==C_Password) {
                delFound=true;
                continue;
            }
            else {
                file.close();
                tempFile.close();
                remove("Temporary_File.txt");
                cout<<"\nInvalid Password\nTry Again";
                return;
            }
        }
        tempFile<<C_AccountNumber<<'\t'
                <<C_FullName<<'\t'
                <<C_FatherName<<'\t'
                <<C_DOB<<'\t'
                <<C_Mobile<<'\t'
                <<C_Aadhar<<'\t'
                <<C_Email<<'\t'
                <<C_Branch<<'\t'
                <<C_IFSC<<'\t'
                <<C_Balance<<'\t'
                <<C_Password<<endl;
    }
    if(delFound) {
        file.close();
        tempFile.close();
        cout<<"Your Account is Permanently Delete";
        remove("Bank_Management_File.txt");
        rename("Temporary_File.txt","Bank_Management_File.txt");
        return;
    }
    file.close();
    tempFile.close();
    cout<<"Account NOT Found\nTry Again";
    remove("Temporary_File.txt");
    return;
}
void BMS :: checkAccount() {
    cout<<"----------|| Account Details ||----------"<<endl;
    cout<<"Enter Your Account Number :: ";
    getline(cin,searchAcc);
    cout<<"Enter Your Password :: ";
    getline(cin,searchPass);
    file.open("Bank_Management_File.txt");
    if(!file) {
        cout<<"\nFile NOT Found";
        return;
    }
    while(getline(file,C_AccountNumber,'\t')) {
        getline(file,C_FullName,'\t');
        getline(file,C_FatherName,'\t');
        getline(file,C_DOB,'\t');
        getline(file,C_Mobile,'\t');
        getline(file,C_Aadhar,'\t');
        getline(file,C_Email,'\t');
        getline(file,C_Branch,'\t');
        getline(file,C_IFSC,'\t');
        getline(file,temp,'\t');
        C_Balance=stoi(temp);
        getline(file,C_Password,'\n');
        if(searchAcc==C_AccountNumber) {
            if(searchPass==C_Password) {
                file.close();
                cout<<"\nAccount Found"<<endl;
                cout<<"----------|| Your Account Details ||---------"<<endl;
                cout<<setw(20)<<"Account Number"<<setw(20)<<"Full Name"
                    <<setw(20)<<"Father Name"<<setw(15)<<"Date of Birth"
                    <<setw(15)<<"Mobile Number"<<setw(15)<<"Aadhar Number"
                    <<setw(30)<<"Email Id"<<setw(15)<<"Branch"
                    <<setw(15)<<"IFSC Code"<<setw(15)<<"Balance"<<setw(30)<<"Password\n"<<endl;

                cout<<setw(20)<<C_AccountNumber<<setw(20)<<C_FullName
                    <<setw(20)<<C_FatherName<<setw(15)<<C_DOB
                    <<setw(15)<<C_Mobile<<setw(15)<<C_Aadhar
                    <<setw(30)<<C_Email<<setw(15)<<C_Branch
                    <<setw(15)<<C_IFSC<<setw(15)<<C_Balance<<setw(30)<<C_Password<<endl;
                return;
            }
            else {
                file.close();
                cout<<"\nInvalid Password\nTry Again";
                return;
            }
        }
    }
    file.close();
    cout<<"\nAccount NOT Found";
    return;
}
void BMS :: exitSystem() {
    cout<<"\nThank You for Using\n----------|| BANK MANAGEMENT SYSTEM ||----------"<<endl;
    cout<<"Your session has ended successfully"<<endl;
    cout<<"Have a Nice Day !"<<endl;
    return;
}
int main() {
    // ⬇️ Object Creation Bank_Management_System
    BMS B;
    int choice;
    while(true) {
        cout<<"\n\n----------|| Bank Management System ||----------"<<endl;
        cout<<"1.  Create Account"<<endl;
        cout<<"2.  Login Account"<<endl;
        cout<<"3.  Forgot Password"<<endl;
        cout<<"4.  Deposit Money"<<endl;
        cout<<"5.  Withdraw Money"<<endl;
        cout<<"6.  Balance Check"<<endl;
        cout<<"7.  Transfer Money"<<endl;
        cout<<"8.  Delete Account"<<endl;
        cout<<"9.  Check Account Details"<<endl;
        cout<<"10. Exit"<<endl;
        while(true) {
            cout<<"\nSo Now ! Enter your choice only Integer :: ";
            string input;
            getline(cin, input);
            bool valid = true;
            for (char ch : input) {
                if (!isdigit(ch)) {
                    valid = false;
                    break;
                }
            }
            if (valid){
                choice = stoi(input);
                break;
            }    
            else
                cout << "Invalid Input\nPlease Try Again\n";
        }
        switch(choice) {
        case 1:
            B.createAccount();
            break;
        case 2:
            B.loginAccount();
            break;
        case 3:
            B.forgotPassword();
            break;
        case 4:
            B.depositMoney();
            break;
        case 5:
            B.withdrawMoney();
            break;
        case 6:
            B.balanceCheck();
            break;
        case 7:
            B.transferMoney();
            break;
        case 8:
            B.deleteAccount();
            break;
        case 9:
            B.checkAccount();
            break;
        case 10:
            B.exitSystem();
            return 0;
        default:
            cout<<"\nInvalid Choice";
        }
    }
    return 0;
}