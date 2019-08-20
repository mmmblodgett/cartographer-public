class Cypher {
private:
    int key;
    char *codedString;
public:
    Cypher(): key(0), codedString(nullptr) {}
    Cypher(string filename);
    Cypher(const Cypher &c);
    ~Cypher();
    string getCode() const;

}

Cypher::Cypher(string filename)
{
    string temp;
    ifstream infile(input);
    if (infile.fail()) 
    {
        cout << "Unable to open " << input << endl;
        exit();
    }
    infile >> key;
    cignore(1, '\n'); // not sure if this is necessary
    getline(infile, temp);
    codedString = new char[temp.size()];
    strcopy(codedString, temp);
    infile.close();
}

Cypher::Cypher(const Cypher &c)
{
    this->key = c.key;
    this->codedString = new char[strlen(c.codedString) + 1];
    strcopy(this->codedString, c.codedString);
}
Cypher::~Cypher()
{
    delete codedString[];
}

string Cypher::getCode() const
{
    return codedString;
}