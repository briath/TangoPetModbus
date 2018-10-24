import pygame
from random import  random
from math import sqrt

SCREEN_SIZE = (1280, 720)


class Vector:

    def __init__(self, point):
        self.point = point

    def __sub__(self, vector): 
        self.point[0] -= vector.point[0]
        self.point[1] -= vector.point[1]

    def __add__(self, vector):  
        self.point[0] += vector.point[0]
        self.point[1] += vector.point[1]

    def length(self):
        return sqrt(self.x * self.x + self.y * self.y)

    def multiply(self, k):
        self.x *= k
        self.y *= k

    def scalar_multiply(self, vector):
        return self.x * vector.x + self.y * vector.y

    def vector(self, vector):
        return sub(y, x)

    def get_point(self):
        return self.point

    def div(self, k):
        if(k == 0):
            return;
        self.point[0] /= k
        self.point[1] /= k


def draw_points(points, style="points", width=4, color=(255, 255, 255)):
    if style == "line":
        for point_number in range(-1, len(points) - 1):
            pygame.draw.line(gameDisplay, color, (int(points[point_number][0]), int(points[point_number][1])),
                             (int(points[point_number + 1][0]), int(points[point_number + 1][1])), width)

    elif style == "points":
        for point in points:
            pygame.draw.circle(gameDisplay, color,
                               (int(point[0]), int(point[1])), width)


def get_point(points, alpha, deg=None):
    if deg is None:
        deg = len(points) - 1
    if deg == 0:
        return points[0]
    return add(multiply(points[deg], alpha), multiply(get_point(points, alpha, deg - 1), 1 - alpha))


def get_points(base_points, count):
    alpha = 1 / count
    result = []
    for i in range(count):
        result.append(get_point(base_points, i * alpha))
    return result


def get_joint(points, count):
    if len(points) < 3:
        return []
    result = []
    for i in range(-2, len(points) - 2):
        pnt = []
        pnt.append(multiply(add(points[i], points[i + 1]), 0.5))
        pnt.append(points[i + 1])
        pnt.append(multiply(add(points[i + 1], points[i + 2]), 0.5))

        result.extend(get_points(pnt, count))
    return result


def display_help():
    gameDisplay.fill((50, 50, 50))
    font1 = pygame.font.SysFont("arial", 30)
    font2 = pygame.font.SysFont("serif", 30)
    data = []
    data.append(['F1', 'Help'])
    data.append(["R", "Reboot"])
    data.append(["P", "Play / Pause"])
    data.append(["Num+", "Add point"])
    data.append(["Num-", "Delete point"])
    data.append(["", ""])
    data.append([str(steps), "current points"])

    pygame.draw.lines(gameDisplay, (255, 50, 50, 255), True, [
                      (0, 0), (800, 0), (800, 600), (0, 600)], 5)
    for item, text in enumerate(data):
        gameDisplay.blit(font1.render(
            text[0], True, (128, 128, 255)), (100, 100 + 30 * item))
        gameDisplay.blit(font2.render(
            text[1], True, (128, 128, 255)), (200, 100 + 30 * item))


def set_points(points, speeds):
    for point in range(len(points)):
        points[point] = add(points[point], speeds[point])
        if points[point][0] > SCREEN_SIZE[0] or points[point][0] < 0:
            speeds[point] = (- speeds[point][0], speeds[point][1])
        if points[point][1] > SCREEN_SIZE[1] or points[point][1] < 0:
            speeds[point] = (speeds[point][0], -speeds[point][1])


if __name__ == "__main__":
    pygame.init()
    gameDisplay = pygame.display.set_mode(SCREEN_SIZE)
    pygame.display.set_caption("Screen Saver")

    steps = 20
    working = True
    points = []
    speeds = []
    show_help = False
    pause = False

    color_param = 0
    color = pygame.Color(0)

    while working:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                working = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    working = False
                if event.key == pygame.K_r:
                    points = []
                    speeds = []
                if event.key == pygame.K_p:
                    pause = not pause
                if event.key == pygame.K_KP_PLUS:
                    steps += 1
                if event.key == pygame.K_F1:
                    show_help = not show_help
                if event.key == pygame.K_KP_MINUS:
                    steps -= 1 if steps > 1 else 0

            if event.type == pygame.MOUSEBUTTONDOWN:
                points.append(event.pos)
                speeds.append((random() * 2, random() * 2))

        gameDisplay.fill((0, 0, 0))
        color_param = (color_param + 1) % 360
        color.hsla = (color_param, 100, 50, 100)
        draw_points(points)
        draw_points(get_joint(points, steps), "line", 4, color)
        if not pause:
            set_points(points, speeds)
        if show_help:
            display_help()

        pygame.display.flip()

    pygame.display.quit()
    pygame.quit()
    exit(0)