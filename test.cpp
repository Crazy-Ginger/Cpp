#include <string>
#include <vector>
using namespace std;

vector<int> primes(100000);
vector <bool> primeCheck(1000001);


vector<int> primeSieve(vector <int> vect)
{
    vector<int>::iterator start = vect.begin();
    vector<int>::iterator end = vect.end();
    if (start == end)
    {
        cout << "No numbers\n";
    }
    else
    {
        //clear the container with 0
        fill(start, end, 0);
        //mark composites with 1 by finding primes and then multiplying them and marking the multiples
        for (vector<int>::iterator checker = start + 1; checker != end; ++checker)
        {
            if (*checker == 1)
            {
                continue;
            }
            //determine the prime number represented by this iterator location
            int stride = (checker - start) + 1;
            //mark all multiples of this prime number up to max
            vector<int>::iterator marker = checker;
            while ((end - marker) > stride)
            {
                //moves marker along the value of stride and assigns marker's value to 1
                advance(marker, stride);
                *marker = 1;
            }
        }

        //copy marked primes into container
        vector<int>::iterator out_it = start;
        for (vector<int>::iterator it = start + 1; it != end; ++it)
        {
            //finds the primes as they are marked with 0
            if (*it == 0)
            {
                //moves the primes towards the front of the list
                *out_it = (it - start) + 1;
                ++out_it;
            }
        }
    }

    //removes the elements of the vector that doesn't contain primes
    vector<int>::iterator mark;
    for (mark = vect.begin(); mark != vect.end(); ++mark)
    {
            if (*mark == 1)
            {
                    vect.erase(mark, vect.end());
                    break;
            }
    }

    //checks for an error that allows 0 to be the last element in the array of vectors
    if (*(--vect.end()) == 0)
    {
            vect.erase(--vect.end());
    }

    return vect;
}


int main(int argc, char* argv[])
{
    primes = primeSieve(primes);

    fill(primeCheck.begin(), primeCheck.end(),false);
    for(vector<int>::iterator i = primes.begin();i!=primes.end();i++)
    {
        primeCheck.at(*i) = true;
    }


    int checkL = stoi(argv[1]);
    string check = to_string(checkL);
    for (int i = check.size()-1; i >= -1; i--)
    {
        for (unsigned int j = 0; j < 10; j++)
        {
            string temp = check.substr(0, i);
            temp += to_string(j);
            temp += check.substr(i+1, check.size());
            if (temp.size() == check.size())
            {
                cout << temp << ", ";
                if (primeCheck.at(stoi(temp)))
                {
                    cout << "true\n";
                }
            }
        }
        cout << endl;
    }
    return 0;
}

