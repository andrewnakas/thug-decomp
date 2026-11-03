struct Node_001D33D8 {
    int m0;
    unsigned short m_flags;
    short m6;
    void* m8;
    virtual void Update();
    virtual ~Node_001D33D8();
};

struct Leaf_001D5050 : Node_001D33D8 {
    virtual void Update();
    virtual ~Leaf_001D5050();
};

Leaf_001D5050::~Leaf_001D5050()
{
}
