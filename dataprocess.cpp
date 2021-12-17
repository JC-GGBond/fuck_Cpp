//data process learning
#include <iostream>
#include <cstring>
int main()
{
    using namespace std;
    //bool
    bool start = 100;
    cout << "force transform 100 to bool \n" << start;
    //transferred meaning char
    cout << "?\n" <<" \\\n " <<"\?\n";
    

    //char
    char letter_a = 'a';
    int i = letter_a;
    cout << letter_a << endl << "i=letter_a=" << i << endl;
    char string_constant[] = "string_constant";
    for (int i=0; i < strlen(string_constant); i++)
        cout <<"now we have letter " << string_constant[i] << endl;
    
    

    
    int m = strlen(string_constant);
    cout << m;
    return(0);
}
