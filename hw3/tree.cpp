void drawTree(int currentDepth, int maxDepth)
{
    if (currentDepth > maxDepth)
        return;

    if (currentDepth <= maxDepth - 2)
    {
        glColor3d(0.45, 0.2, 0.05);
        glLineWidth(10 * static_cast<GLfloat>(pow(TREE_FACTOR, currentDepth)));
    }
    else
    {
        glColor3d(0, 0.5, 0);
        glLineWidth(30 * static_cast<GLfloat>(pow(TREE_FACTOR, currentDepth)));
    }

    double lineLen = TREE_LINE_BASE_LEN * pow(TREE_FACTOR, currentDepth);
    glBegin(GL_LINES);
    glVertex2d(0, 0);
    glVertex2d(0, lineLen);
    glEnd();

    int angle1 = 10 + rand() % 40;
    int angle2 = 10 + rand() % 40;

    glTranslated(0, lineLen, 0);
    glRotated(-angle1, 0, 0, 1);
    drawTree(currentDepth + 1, maxDepth);
    glRotated(angle1 + angle2, 0, 0, 1);
    drawTree(currentDepth + 1, maxDepth);
    glRotated(-angle2, 0, 0, 1);
    glTranslated(0, -lineLen, 0);
}
