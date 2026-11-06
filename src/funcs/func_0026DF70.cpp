struct Col_0026DF70 {
    unsigned char m0;
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

void Set_0026DF70(Col_0026DF70* c, unsigned char* rgb)
{
    c->r = rgb[0];
    c->g = rgb[1];
    c->b = rgb[2];
    c->a = 0;
}
