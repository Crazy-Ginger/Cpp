#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


class v3
{
    public:

    v3();
    v3(char* bin);
    v3(double x, double y, double z);
    ~v3();

    double m_x, m_y, m_z;

};

v3::v3(char* facet)
{
    char f1[4] = {facet[0],facet[1],facet[2],facet[3]};

    char f2[4] = {facet[4],facet[5],facet[6],facet[7]};

    char f3[4] = {facet[8],facet[9],facet[10],facet[11]};

    float xx = *((float*) f1 );
    float yy = *((float*) f2 );
    float zz = *((float*) f3 );

    m_x = double(xx);
    m_y = double(yy);
    m_z = double(zz);
}


class tri
{
    public:

    tri();
    tri(v3 p1, v3 p2, v3 p3);
    void draw();
    ~tri();

    v3 m_p1, m_p2, m_p3;
};


void read_stl(string fname, vector <tri>&v)
{
    //!!
    //don't forget ios::binary
    //!!
    ifstream myFile (fname.c_str(), ios::in | ios::binary);

    char header_info[80] = "";
    char nTri[4];
    unsigned long nTriLong;

    //read 80 byte header
    if (myFile)
    {
        myFile.read (header_info, 80);
        cout <<"header: " << header_info << endl;
    }
    else
    {
        cout << "error" << endl;
        return;
    }

    //read 4-byte ulong
    if (myFile) 
    {
        myFile.read (nTri, 4);
        nTriLong = *((unsigned long*)nTri) ;
        cout <<"n Tri: " << nTriLong << endl;
    }
    else
    {
        cout << "error" << endl;
        return;
    }

    //now read in all the triangles
    for(unsigned int i = 0; i < nTriLong; i++)
    {
        char facet[50];
        if (myFile) 
        {
            //read one 50-byte triangle
            myFile.read (facet, 50);

            //populate each point of the triangle
            //using v3::v3(char* bin);
            //facet + 12 skips the triangle's unit normal
            v3 p1(facet+12);
            v3 p2(facet+24);
            v3 p3(facet+36);

            //add a new triangle to the array
            v.push_back( tri(p1,p2,p3) );
        }
    }
}
