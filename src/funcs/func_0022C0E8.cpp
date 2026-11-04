class Shared_0022C0E8 {
public:
    int m_pad[5];
    virtual ~Shared_0022C0E8();
};

extern Shared_0022C0E8* D_0038FC78;
extern unsigned int D_0038FC7C;

void Release_0022C0E8()
{
    if (D_0038FC7C > 1) {
        D_0038FC7C--;
        return;
    }
    if (D_0038FC78)
        delete D_0038FC78;
    D_0038FC78 = 0;
    D_0038FC7C = 0;
}
