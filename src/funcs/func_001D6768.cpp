struct Node_001D33D8 {
    int m0;
    unsigned short m_flags;
    short m6;
    void* m8;
    virtual void Update();
    virtual ~Node_001D33D8();
};

struct Node_001D4D50 : Node_001D33D8 {
    virtual void Update();
    virtual ~Node_001D4D50();
};

struct Sub_001D6768 : Node_001D4D50 {
    virtual void Update();
    virtual ~Sub_001D6768();
};

Sub_001D6768::~Sub_001D6768()
{
}
