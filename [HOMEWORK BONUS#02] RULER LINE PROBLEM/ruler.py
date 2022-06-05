import turtle

class Ruler:
    def __init__(self, l, h):
        self.l = l
        self.h = h
        self.lines = []
        
    def set_rulerline(self):
        self.lines = []
        def ruler_line(h, l, r):
            if h > 0:
                m = (l + r ) / 2
                self.lines.append([m, h])
                ruler_line(h-1, l, m)
                ruler_line(h-1, m, r)
        ruler_line(self.h-1, 0, self.l)
        return self.lines
        
    def display(self): 
        ruler = turtle.Turtle()
        ruler.speed(1)
        
        # Draw ruler's background
        ruler.color('#008000')
        ruler.fillcolor('#008000')
        ruler.penup()
        ruler.goto(0, 0)
        ruler.pendown()
        ruler.begin_fill()
        ruler.forward(self.l*10)
        ruler.left(90)
        ruler.forward(self.h*10)
        ruler.left(90)
        ruler.forward(self.l*10)
        ruler.left(90)
        ruler.forward(self.h*10)
        ruler.left(180)
        ruler.penup()
        ruler.end_fill()
        
        # Draw ruler line
        ruler.color('#000000')
        for line in self.lines:
            ruler.goto(line[0]*10, 0)
            ruler.pendown()
            ruler.forward(line[1]*10)
            ruler.penup()
        turtle.done()
        # result = ruler.getscreen()
        # result.getcanvas().postscript(file="result.jpg")
        