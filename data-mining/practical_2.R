setwd("C:\\Users\\purnima\\OneDrive\\Documents\\RPrograms")

irisfile <- file.choose()
irisdata <- read.csv(irisfile, header=TRUE, sep=",")
irisdata

# observations that are complete
d <- 0
c <- complete.cases(irisdata)
for (i in c) {
  if (i == TRUE) {
    d <-  d + 1
  }
}
print("Complete values:- ")
d
print("Percentage of complete values:-")
d * (100/150)

# replace all special values with NA
library(naniar)
replace_with_na_all(irisdata, Sepal.Width < 0)

