struct Node_001D4D50 {
    int m0;
    int m4;
    void* m8;
    virtual void Update();
    virtual ~Node_001D4D50();
};

struct Leaf_001D5238 : Node_001D4D50 {
    virtual void Update();
    virtual ~Leaf_001D5238();
};

Leaf_001D5238::~Leaf_001D5238()
{
}
