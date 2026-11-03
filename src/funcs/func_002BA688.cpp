struct Obj_002BA688 {
    void GetPair(int n, int* a, int* b);
};

void Obj_002BA688::GetPair(int n, int* a, int* b)
{
    int v;
    switch (n) {
    case 1: v = 1; break;
    case 2: *a = 0; *b = 0; return;
    case 3: *a = 2; *b = 7; return;
    case 4: *a = 8; *b = 13; return;
    case 5: v = 14; break;
    case 6: v = 15; break;
    case 7: v = 16; break;
    case 8: v = 17; break;
    default: return;
    }
    *a = v;
    *b = v;
}
