bool judgeCircle(char* moves) {
    char *c = moves;
    bool isCircle = false;
    int v = 0, h = 0;
    
    while (*c != '\0') {
        switch (*c) {
            case 'R':
                ++h;
                break;
            case 'L':
                --h;
                break;
            case 'U':
                ++v;
                break;
            case 'D':
                --v;
                break;
        }
        ++c;
    }
    
    if (!v && !h)   // v == 0 && h == 0
        return true;
    return false;
}