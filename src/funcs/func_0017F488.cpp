extern int D_0038882C;
extern float D_0038C0FC;
extern float D_0038C100;

void Set_0017F488()
{
    bool on = D_0038882C == 1;
    if (on) {
        D_0038C0FC = 1.0f;
        D_0038C100 = 1.0f;
    } else {
        D_0038C0FC = 0.8f;
        D_0038C100 = 1.1428572f;
    }
}
