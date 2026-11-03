struct Vec17AD80 {
    float x, y, z;
};

extern Vec17AD80 D_003E1630;

void Set17AD80(const Vec17AD80* v)
{
    D_003E1630.x = v->x;
    D_003E1630.y = v->y;
    D_003E1630.z = v->z;
}
