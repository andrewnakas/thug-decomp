extern "C" float fabsf(float);

extern "C" float func_001001B8(float cur, float target, float step)
{
    step = fabsf(step);
    if (cur < target) {
        if (step < target - cur) return target - step;
    } else {
        if (step < cur - target) goto above;
    }
    return cur;
above:
    return target + step;
}
