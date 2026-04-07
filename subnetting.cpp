#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>


using namespace std;

void IP_Handling(string &ip, int &ip1, int &ip2, int &ip3, int &ip4, int &cidr)
{
    int i1, i2, i3, i4;
    int l = ip.length();
    int j = 1;
    for (int i = 0; i < ip.length(); i++)
    {
        if (ip[i] == '.' and j == 1)
        {
            i1 = i;
            j++;
            i++;
        }
        else if (ip[i] == '.' and j == 2)
        {
            i2 = i;
            j++;
            i++;
        }

        else if (ip[i] == '.' and j == 3)
        {
            i3 = i;
            j++;
            i++;
        }

        else if (ip[i] == '/') i4 = i;
    }

    ip1 = stoi(ip.substr(0, i1));
    ip2 = stoi(ip.substr(i1 + 1, i2 - (i1 + 1)));
    ip3 = stoi(ip.substr(i2 + 1, i3 - (i2 + 1)));
    ip4 = stoi(ip.substr(i3 + 1, i4 - (i3 + 1)));
    cidr = stoi(ip.substr(i4 + 1));
    
}
// For next network
void add_block(int &ip1, int &ip2, int &ip3, int &ip4, int block_size){
    if(block_size <= 255){
            ip4 += block_size;

        if(ip4 > 255){
            ip3 += ip4 / 256;
            ip4 %= 256;
        }

        if(ip3 > 255){
            ip2 += ip3 / 256;
            ip3 %= 256;
    }

    if(ip2 > 255){
        ip1 += ip2 / 256;
        ip2 %= 256;
    }
    }

}

void Subnet_Musk(int &cidr, int &ones, int &zeros, int &interesting_octet_position, int &sub_musk, int &subnets, int &block_size,string &ni,string &b,string  &fhi,string &lhi,string &nni,string &sm, string &sr, string &uhr,int &ip1,int &ip2,int &ip3, int &ip4)
{   
    sub_musk = 0;
    int arr[] = {128, 64, 32, 16, 8, 4, 2, 1};

    ones = cidr % 8;
    zeros = 32 - cidr;
    interesting_octet_position = cidr / 8 + 1;
    for (int i = 0; i < ones; i++) sub_musk = sub_musk + arr[i];
    subnets = pow(2, ones);
    block_size = 255 - sub_musk + 1;


    if (interesting_octet_position == 4)
    {

        // Network ID
        int net_id = (ip4 / block_size) * block_size;
        ni = to_string(ip1) + '.' + to_string(ip2) + '.' + to_string(ip3) + '.' + to_string(net_id);

        // Broadcast IP
        int brd_ip = net_id + block_size - 1;
        b = to_string(ip1) + '.' + to_string(ip2) + '.' + to_string(ip3) + '.' + to_string(brd_ip);

        // First Host IP
        int first_ip = (ip4 / block_size) * block_size + 1;
        fhi = to_string(ip1) + '.' + to_string(ip2) + '.' + to_string(ip3) + '.' + to_string(first_ip);

        // Last Host IP
        int last_ip = net_id + block_size - 2;
        lhi = to_string(ip1) + '.' + to_string(ip2) + '.' + to_string(ip3) + '.' + to_string(last_ip);

        // Next Network
        int nx_net = net_id + block_size;
        if(nx_net >= 256) nni = to_string(ip1) + "." + to_string(ip2) + "." + to_string(ip3 + 1) + to_string(nx_net - 256) ;
        else nni = to_string(ip1) + "." + to_string(ip2) + "." + to_string(ip3) + "." + to_string(nx_net);
        

        // Subnet Musk
        
        sm = "255.255.255." + to_string(sub_musk);
        
        // Subnet Range
        sr = ni + " - " + b;

        // Usable Host Range
        uhr = fhi + " - " + lhi;
        
    }

    if (interesting_octet_position == 3)
    {
        // Network ID
        int net_id = (ip3/block_size) * block_size;
        ni = to_string(ip1) + '.' + to_string(ip2) + '.' + to_string(net_id) + ".0";

        // Broadcast IP
        int brd_ip = net_id + block_size - 1;
        b = to_string(ip1) + '.' + to_string(ip2) + '.' + to_string(brd_ip) + ".255";

        // First Host IP
        fhi = to_string(ip1) + '.' + to_string(ip2) + '.' + to_string(net_id) + ".1";

        // Last Host IP
        int nx_net_ip = net_id + block_size - 1;
        lhi = to_string(ip1) + '.' + to_string(ip2) + '.' + to_string(nx_net_ip) + ".254";

        // Next Network ID
        int nx_net = net_id + block_size;
        if(nx_net >= 256) nni = to_string(ip1) + "." + to_string(ip2 + 1) + "." + to_string(nx_net - 256) + ".0" ;
        else nni = to_string(ip1) + "." + to_string(ip2) + "." + to_string(nx_net) + ".0";


        // Subnet Musk
        sm = "255.255." + to_string(sub_musk) + ".0";   

        // Subnet Range
        sr = ni + " - " + b;

        // Usable Host Range
        uhr = fhi + " - " + lhi;
    }

    if(interesting_octet_position == 2){
        // Network ID
        int net_id = (ip2/block_size) * block_size;
        ni = to_string(ip1) + '.' + to_string(net_id) + ".0.0";

        // Broadcast IP
        int brd_ip = net_id + block_size - 1;
        b = to_string(ip1) + '.' + to_string(brd_ip) + ".255.255";


        // First Host IP
        fhi = to_string(ip1) + '.' + to_string(net_id) + ".0.1";

        // Last Host IP
        int nx_net_ip = net_id + block_size - 1;
        lhi = to_string(ip1) + '.' + to_string(nx_net_ip) + ".255.254";

        // Next Network ID
        int nx_net = net_id + block_size;
        if(nx_net >= 256) nni = to_string(ip1 + 1) + "." + to_string(nx_net - 256) + ".0.0" ;
        else nni = to_string(ip1) + "." + to_string(nx_net) + "0.0";


        // Subnet Musk
        sm = "255." + to_string(sub_musk) + ".0.0";

        // Subnet Range
        sr = ni + " - " + b;

        // Usable Host Range
        uhr = fhi + " - " + lhi;

    }

    if(interesting_octet_position == 1){
        // Network ID
        int net_id = (ip1/block_size) * block_size;
        ni = to_string(ip1) + ".0.0.0";

        // Broadcast IP
        int brd_ip = net_id + block_size - 1;
        b = to_string(ip1) + ".255.255.255";


        // First Host IP
        fhi = to_string(ip1) + ".0.0.1";

        // Last Host IP
        int nx_net_ip = net_id + block_size - 1;
        lhi = to_string(ip1) + ".255.255.254";

        // Next Network ID
        int nx_net = net_id + block_size;
        if(nx_net >= 256) cout<<"No Next Network!";
        else nni = to_string(nx_net) +  ".0.0.0";


        // Subnet Musk
        sm = to_string(sub_musk) + ".0.0.0";

        // Subnet Range
        sr = ni + " - " + b;

        // Usable Host Range
        uhr = fhi + " - " + lhi;
    }


}

void Find_Subnet_Details(string ni, string b, string fhi, string lhi,string nni, string sm, string sr, string uhr, int ones, int zeros, int cidr, int block_size, int subnets){
    int oness = (cidr/8) * 8 + ones;
    // Printing Subnet Details
    cout<< "Subnet Details... \n";

    cout<< "Network ID        : " << ni << endl;
    cout<< "Broadcast         : " << b<<endl;
    cout<< "First Host IP     : " << fhi<<endl;
    cout<< "Last Host IP      : " << lhi<<endl;
    cout<< "Next Network ID   : " << nni<<endl;
    cout<< "Subnet Mask       : " << sm<<endl;

    cout<< "Subnet Range      : " << sr<<endl;
    cout<< "Usable Host Range : " << uhr<<endl;
    
    cout << "Netorks Bits      : " << oness << endl;
    cout << "Host Bits         : " << zeros << endl;
    cout << "CIDR              : " << cidr << endl;
    cout << "Block Size        : " << block_size << endl;
    cout << "Subnets           : " << subnets << endl;
    cout << "IP Addresses      : " << pow(2, zeros) << endl;
    cout << "Number of Hosts   : " << pow(2, zeros) - 2 << endl;

}

void banner(){
    cout<<"                                               +========================================+\n";
    cout<<"                                               | Auther     : Arpan Kanti Das           |\n";
    cout<<"                                               | Tool       : Subnet-ing               |\n";
    cout<<"                                               | Technology : C++                       |\n";
    cout<<"                                               | Github     : 01arpan                  |\n";
    cout<<"                                               | E-mail     : arpankantidas9@gmail.com  |\n";
    cout<<"                                               +=======================================+\n";

}


int  FLSM(int &cidr, int &ones, int &zeros, int &interesting_octet_position, int &sub_musk, int &subnets, int &block_size,string &ni,string &b,string  &fhi,string &lhi,string &nni,string &sm, string &sr, string &uhr,int &ip1,int &ip2,int &ip3, int &ip4, string &IPF, int nf, int &iF,int nnf){
    int IP4 = ip4;int j = 0;

    cout<<"  "<<iF<<"  "<<"          "<<ni <<"          ";
    while (IP4  != 0){
        IP4 = IP4/10;
        j++;    
    }
    int i = 5 -j;
    while(i--) cout<<" ";
    
    
    cout<<uhr<<"             "<<b<<endl; 
    
    iF++;
    if(iF == nnf+1) return 0; // Exiting after printing number of sunnet times

    // Calling FLSM Function(Recursive)
    

    // IP Handling
    IPF = nni + '/' + to_string(cidr);
    IP_Handling(IPF, ip1, ip2, ip3, ip4, cidr);
    Subnet_Musk(cidr, ones, zeros, interesting_octet_position, sub_musk, subnets, block_size,ni,b,fhi,lhi,nni,sm,sr,uhr,ip1,ip2,ip3,ip4);
    FLSM(cidr, ones, zeros, interesting_octet_position, sub_musk, subnets, block_size,ni,b,fhi,lhi,nni,sm,sr,uhr,ip1,ip2,ip3,ip4,IPF,nf,iF,nnf);
            
}


int main()
{
    banner();
    cout<<"\nDon't stuck at Subnetting,Just Lemme know the\n";
    
    in_ch:

    // Input, Inisialaization and Calling function to handle the IP
    string ip,ni,b,fhi,lhi,nni,sm,sr,uhr,IP,IPF;
    int ip1, ip2, ip3, ip4, cidr, i1, i2, i3, i4,dot_count = 0,slash_count = 0,dot_slash = 1, slash_flag = 1;
    
    cout<<"Target IP: ";// GO TO junction
    cin >> ip;
    IP = ip;

    if(ip == "Exit" or ip == "exit") return 0;

    // 1st Input Validation
    for(int i = 0; i < ip.length(); i++){
        if(i < 7 and ip[i] == '/') slash_flag = 0;
        if(ip[i] == '.') dot_count++;
        else if(ip[i] == '/') slash_count++;
        if(slash_count >= 1 and dot_count < 3) dot_slash = 0;
    }
    
    if( dot_count != 3 or slash_count != 1 or dot_slash == 0 or slash_flag == 0){
        cout<<"Invalid IP!!\nPlease Enter Correct IPv4 Format.(Ex- 204.175.253.10/25)\n";
        goto in_ch;
    }
    
    
    // IP Handling
    IP_Handling(ip, ip1, ip2, ip3, ip4, cidr);

    // 2nd Input Validation
    if((ip.length() > 18 or ip.length() < 9) or (cidr < 0 or cidr > 32) or ((ip1 < 0 or ip2 < 0 or ip3 < 0 or ip4 < 0) or (ip1 > 255 or ip2 > 255 or ip3 > 255 or ip4 > 255))){
        cout<<"Invalid IP!!\nPlease Enter Correct IPv4 Format.(Ex- 204.175.253.10/25)\n";
        goto in_ch;
    }
    

    
    
    
    // Subnet_Musk Calculation
    int ones, zeros, interesting_octet_position, sub_musk = 0, subnets, block_size;
    Subnet_Musk(cidr, ones, zeros, interesting_octet_position, sub_musk, subnets, block_size,ni,b,fhi,lhi,nni,sm,sr,uhr,ip1,ip2,ip3,ip4);

    // Clear Screen
    cout << "\033[2J\033[1;1H";
    banner();// Show banner
    // Show Load
    cout<<"\nTarget IP Loaded: "<<ip<<endl;
    
    cin.get();
    cin.get();
    


    cout << "\033[2J\033[1;1H";
    banner();
    cout<<"\nTarget IP Loaded: "<<ip<<endl<<endl;

    
    cmd_line:
    // Command Line
    cout << "\033[2J\033[1;1H";
    banner();
    cout<<"\nTarget IP Loaded: "<<ip<<endl<<endl;
    cout<<"What You Wanna DO?\n0. Change Target IP\n1. Find Subnet Details\n2. FLSM\n3. VLSM\n4. Exit\n";
    string cmd;
    cout<<"\n$ ";
    cin>>cmd;

    if(cmd == "0") {
        cout << "\033[2J\033[1;1H";
        banner();
        cout<<endl;
        cout<<"Changing target IP...\n";
        cout<<"\nTarget IP Loaded: "<<ip<<endl;
        goto in_ch;
        
        
    } // GO TO changing input
    else if(cmd == "1"){
        cout << "\033[2J\033[1;1H";
        banner();
        cout<<"\nTarget IP Loaded: "<<ip<<endl<<endl;
        Find_Subnet_Details(ni, b, fhi, lhi, nni, sm,sr,uhr, ones, zeros, cidr, block_size, subnets);
        

    } // Call Find_Subnet_Details()
    else if(cmd == "2"){
       
        cout << "\033[2J\033[1;1H";
        banner();
        cout<<"\nTarget IP Loaded: "<<ip<<endl;

        Num_of_Subnets:

        // Inputing number of subnets
        int nf,cidr_shifter,iF = 1;
        cout<<"Number of Subnets: ";
        cin>> nf;
        int nnf = nf;

        

        

        // Finding new CIDR
        cidr_shifter = ceil(log2(nf));
        cidr = cidr + cidr_shifter;
        
        
        cout<<"CIDR of Subnets: "<< cidr<<endl<<endl;
        IPF = ni + '/' + to_string(cidr);
    
        IP_Handling(IPF, ip1, ip2, ip3, ip4, cidr);
        Subnet_Musk(cidr, ones, zeros, interesting_octet_position, sub_musk, subnets, block_size,ni,b,fhi,lhi,nni,sm,sr,uhr,ip1,ip2,ip3,ip4);
        
        
        
        // Subnets
        cout<<" Subnet"<<"       "<<"    Network IP"<< "                        "<<"Host Range"<<"                       "<<"Brodcast"<<endl;
        cout<<endl;

        FLSM(cidr, ones, zeros, interesting_octet_position, sub_musk, subnets, block_size,ni,b,fhi,lhi,nni,sm,sr,uhr,ip1,ip2,ip3,ip4,IPF,nf,iF,nnf);
        
        
        

        ip = IP;

    } // Call FLSM()
    else if(cmd == "3"){
        cout << "\033[2J\033[1;1H";
        banner();
        cout<<"\nTarget IP Loaded: "<<ip<<endl;
        cout<<"Under Development!!\n";} // Call VLSM()
    else if(cmd == "4" or cmd == "Exit" or cmd == "exit") return 0;
    else{
        cout << "\033[2J\033[1;1H";
        banner();
        cout<<"\n$ "<<cmd<<endl;
        cout<<"Worng Command!!\n";
        
        
    }
    cin.get();
    cin.get();
    goto cmd_line;// GO TO Command again


    return 0;
        
       
}
