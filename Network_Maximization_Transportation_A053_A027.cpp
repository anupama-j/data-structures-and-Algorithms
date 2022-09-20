//NAME : Jatin Mandliya , Keyur Mistry
//Roll no : A053 , A027
//Topic :  Network Maximization-Transportation

#include<iostream>
#include<iomanip>
using namespace std;

const int number_of_Warehouses = 3,number_of_Outlets = 4;

int transportation_cost_per_unit[number_of_Warehouses][number_of_Outlets] = {
    {16,16,16,4},
    {7,4,12,16},
    {0,16,4,0}
};

int transportation_cost_per_unit_after_minimized[number_of_Warehouses][number_of_Outlets];
int graph[number_of_Warehouses][number_of_Outlets];


int demands_at_outlet[number_of_Outlets] = {250,350,450,150};
int supply_by_warehouse[number_of_Warehouses] = {500,400,300};

string outlet_names[number_of_Outlets];
string warehouse_names[number_of_Warehouses];


void set_warehouse_and_outlet_names(){
    string warehouse = "Warehouse";
    string outlet = "Outlet";
    for (int i = 0; i < number_of_Warehouses; i++)
    {
        warehouse_names[i] = warehouse+"-"+char(i+65);
    }
    
    for (int j = 0; j < number_of_Outlets; j++)
    {
        outlet_names[j] = outlet+"-"+char(j+65);
    }
    
}

int sum(int arr[],int size){
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum+=arr[i];
    }
    return sum;
}

void display_table(int transportation_cost_per_unit[][number_of_Outlets] = transportation_cost_per_unit,int demands_at_outlet[] = demands_at_outlet,int supply_by_warehouse[] = supply_by_warehouse){
    set_warehouse_and_outlet_names();
    // cout<<sum(demands_at_outlet,4);
    cout<<"\n\n\t   ";
    for (int a = 0; a < number_of_Outlets; a++)
    {
        cout<<setw(11)<<outlet_names[a];
    }
    cout<<"\t   QUANTITY\n";
    for (int i = 0; i < number_of_Warehouses; i++)
    {
        cout<<warehouse_names[i];
        for (int j = 0; j < number_of_Outlets; j++)
        {
            cout<<setw(10)<<transportation_cost_per_unit[i][j]<<" ";
        }
        cout<<setw(11)<<supply_by_warehouse[i]<<"\n";
    }
    cout<<"  DEMAND  ";
    for (int b = 0; b < number_of_Outlets; b++)
    {
        cout<<setw(11)<<demands_at_outlet[b];
    }
    if(sum(supply_by_warehouse,number_of_Warehouses) == sum(demands_at_outlet,number_of_Outlets)){
        cout<<setw(12)<<sum(demands_at_outlet,number_of_Outlets)<<"\n\n\n";
    }
    else{
        cout<<setw(12)<<"--"<<"\n\n\n";
    }
}





void maximization_to_minimization_conversion(int maximum_cost){
    for (int i = 0; i < number_of_Warehouses; i++)
    {
        for (int j = 0; j < number_of_Outlets; j++)
        {
            transportation_cost_per_unit_after_minimized[i][j] =  maximum_cost - transportation_cost_per_unit[i][j];
            // cout<<transportation_cost_per_unit_after_minimized[i][j]<<endl;
        }
    }
}

int find_minimum_cost(int transportation_cost_per_unit_after_minimized[][number_of_Outlets]){
    int minimum;

    for(int i = 0;i < number_of_Warehouses;i++){
        if(supply_by_warehouse[i] == 0){
            continue;
        }
        for(int j = 0;j < number_of_Outlets;j++){
            if(demands_at_outlet[j] == 0){
                continue;
            }
            minimum = transportation_cost_per_unit_after_minimized[i][j];
            break;
        }
    }


    
    for (int i = 0; i < number_of_Warehouses; i++)
    {
        if (supply_by_warehouse[i] == 0)
        {
            continue;
        }
        for (int j = 0; j < number_of_Outlets; j++)
        {
            if (demands_at_outlet[j] == 0)
            {
                continue;   
            }
            if (transportation_cost_per_unit_after_minimized[i][j] < minimum)
            {
                minimum = transportation_cost_per_unit_after_minimized[i][j];
            }
            
        }   
    }
    return minimum;
}

int isValueCorrect(){
    if(sum(demands_at_outlet,number_of_Outlets) != sum(supply_by_warehouse,number_of_Warehouses)){
        cout<<"\nTotal Supply Is Not Matching with Total Demand\nPlease enter correct value\n";
        int flag3 = 0;
        cout<<"\n(Total Demand)(";
        for (int i = 0; i < number_of_Outlets; i++)
        {
            if(flag3){
                cout<<" + ";
            }
            flag3 = 1;
            cout<<demands_at_outlet[i];
        }
        cout<<") = "<<sum(demands_at_outlet,number_of_Outlets)<<" Which is Not Equal to (";

        flag3 = 0;
        for (int j = 0; j < number_of_Warehouses; j++)
        {
            if(flag3){
                cout<<" + ";
            }
            flag3 = 1;
            cout<<supply_by_warehouse[j];
        }
        cout<<")(Total Supply) = "<<sum(supply_by_warehouse,number_of_Warehouses)<<"\n\n";
        return 0;
    }
    return 1;
}

void Least_Cost_Method(){
    if(!isValueCorrect()){
        return;
    }
    int flag = 0;
    int m = 0;
    while(sum(supply_by_warehouse,number_of_Warehouses) > 0 && sum(demands_at_outlet,number_of_Outlets) >= 0)
    {    
        for (int i = 0; i < number_of_Warehouses; i++)
        {
            if (supply_by_warehouse[i] == 0)
            {
                continue;
            }
            
            for (int j = 0; j < number_of_Outlets; j++)
            {
                // cout<<i<<" "<<j<<endl;
                if (demands_at_outlet[j] == 0)
                {
                    continue;
                }
                if (transportation_cost_per_unit_after_minimized[i][j] == find_minimum_cost(transportation_cost_per_unit_after_minimized))
                {
                    // cout<<find_minimum_cost(transportation_cost_per_unit_after_minimized);
                    flag = 1;
                    // display_table(transportation_cost_per_unit_after_minimized,demands_at_outlet,supply_by_warehouse);
                    int difference = 0;
                    if (supply_by_warehouse[i] >= demands_at_outlet[j])
                    {
                        difference = demands_at_outlet[j];
                        supply_by_warehouse[i]-=demands_at_outlet[j];
                        demands_at_outlet[j] = 0;
                    }
                    else
                    {
                        difference = supply_by_warehouse[i];
                        demands_at_outlet[j]-=supply_by_warehouse[i];
                        supply_by_warehouse[i] = 0;
                    }
                    graph[i][j] = difference;
                    break;
                }
                
            }
            if (flag){
                flag = 0;
                break;
            }
            
        }
        display_table(transportation_cost_per_unit_after_minimized);
        if(m == 1200){
            break;
        }
        m++;
    }
    cout<<"\n\nNow to get Maximum Net Return,the Supplied(Transported) Quantity Will Multiplied By Actual Cost\n\n";
    display_table(transportation_cost_per_unit);
    int optimum_cost = 0;
    int flag2 = 0;
    cout<<"The Maximum Net Return = ";
    for (int i = 0; i < number_of_Warehouses; i++)
    {
        for (int j = 0; j < number_of_Outlets; j++)
        {
            if (graph[i][j])
            {
                if (flag2)
                {
                    cout<<" + ";
                }
                flag2 = 1;
                cout<<"("<<graph[i][j]<<" X "<<transportation_cost_per_unit[i][j]<<")";
                optimum_cost+=(graph[i][j]*transportation_cost_per_unit[i][j]);
            }
            
        }
        
    }
    cout<<" = "<<optimum_cost<<endl;
}


void print_info(){
    set_warehouse_and_outlet_names();
    cout<<"\n\nTransportation Cost Per Unit From Source To Destination\n\n";
    for (int i = 0; i < number_of_Warehouses; i++)
    {
        for (int j = 0; j < number_of_Outlets; j++)
        {
            cout<<"Transportation Cost Per Unit For Transfering Goods from \""<<warehouse_names[i]<<"\" to \""<<outlet_names[j]<<"\" is "<<transportation_cost_per_unit[i][j]<<endl;
        }
    }
    cout<<"\n\n";
    for (int k = 0; k < number_of_Warehouses; k++)
    {
        cout<<"Total Quantity Supplied By \""<<warehouse_names[k]<<"\" is "<<supply_by_warehouse[k]<<endl;
    }
    cout<<"\n\n";
    for (int l = 0; l < number_of_Outlets; l++)
    {
        cout<<"Total Demand At Outlet \""<<outlet_names[l]<<"\" is "<<demands_at_outlet[l]<<endl;
    }
    
    
}



int main(){
    if (!isValueCorrect())
    {
        exit(0);
    }
    
    int maximum_number = 0;
    for (int a = 0; a < number_of_Warehouses; a++)
    {
        for (int b = 0; b < number_of_Outlets; b++)
        {
            graph[a][b] = 0;
        }
        
    }
    
    for (int i = 0; i < number_of_Warehouses; i++)
    {
        for (int j = 0; j < number_of_Outlets; j++)
        {
            if (transportation_cost_per_unit[i][j] > maximum_number)
            {
                maximum_number = transportation_cost_per_unit[i][j];
            }
            
        }
        
    }

    print_info();

    cout<<"\nData In Tabular Form\n";
    display_table(transportation_cost_per_unit);

    cout<<"\nConversion From Maximization to Minimization\n";
    cout<<"\nThe Maximum Cost is "<<maximum_number<<"\nSubstracting All Cost From "<<maximum_number<<"\n";
    maximization_to_minimization_conversion(maximum_number);
    cout<<"\nTable After Conversion in Minimization\n";
    display_table(transportation_cost_per_unit_after_minimized);

    cout<<"Using \"Matrix Minimum Method\" to Find Feasible Solution";
    Least_Cost_Method();


    return 0;
}