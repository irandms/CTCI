class matrix(object):
    def __init__(self, rowcount, colcount):
        self.rows, self.cols = rowcount, colcount
        self.data = [[0 for x in range(self.cols)] for y in range(self.rows)]
        i = 0;

        for row in range(self.rows):
            for col in range(self.cols):
                self.data[row][col] = i
                i = i + 1

    def __str__(self):
        ret = ""
        for row in range(self.rows):
            ret = ret + "["
            for col in range(self.cols):
                ret = ret + " {} ".format(self.data[row][col])
            ret = ret + "]\n"
        return ret

    def zero(self):
        zero_rows = [False for x in range(self.rows)]
        zero_cols = [False for x in range(self.cols)]

        for row in range(self.rows):
            for col in range(self.cols):
                if self.data[row][col] == 0:
                    zero_rows[row] = True
                    zero_cols[col] = True

        for row in range(self.rows):
            if zero_rows[row] is True:
                for col in range(self.cols):
                    self.data[row][col] = 0

        for col in range(self.cols):
            if zero_cols[col] is True:
                for row in range(self.rows):
                    self.data[row][col] = 0

my_matrix = matrix(3,4)
print(my_matrix)
my_matrix.zero()
print(my_matrix)
