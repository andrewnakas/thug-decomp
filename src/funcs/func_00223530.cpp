float Angle_00223530(float a)
{
    while (a < 0.0f) {
        a += 360.0f;
    }
    while (a > 360.0f) {
        a -= 360.0f;
    }
    return a;
}
