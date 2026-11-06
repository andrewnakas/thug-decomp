/* sym: Detach__13Node_0016DB90P13Node_0016DB90 = 0x0016DB28 */
struct Node_0016DB90 {
    char pad0[0x1C];
    unsigned int m1C;
    Node_0016DB90* m20;
    int m24;
    Node_0016DB90* m28;
    bool Fn(Node_0016DB90* parent);
    bool Detach(Node_0016DB90* parent);
    Node_0016DB90* First() { return m20; }
};


bool Node_0016DB90::Fn(Node_0016DB90* parent)
{
    if ((m1C & 2) || !parent->m20)
        return false;
    for (Node_0016DB90* c = parent->m20; c; c = c->m28) {
        if (Detach(c))
            return true;
    }
    return false;
}
