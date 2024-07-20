# set the directory path for the file
setwd("C:\\Users\\purnima\\OneDrive\\Documents\\RPrograms")

peoplefile <- file.choose() # choose file from the directory
peopledata <- read.table(peoplefile, header = TRUE, sep = ",") # read the data from file
peopledata # print the data

edit(peopledata) # enables us to edit a R object

# install necessary packages
install.packages("sqldf")
library(sqldf)

# Create Rule sets
# RULE SET 1 : The age should be in the range 0-150
query1 <- "SELECT * FROM peopledata WHERE Age >= 0 AND Age <= 150"
sqldf(query1)

# RULE SET 2 : The age should be greater than yearsmarried
query2 <- "SELECT * FROM peopledata WHERE Age > Yearsmarried"
sqldf(query2)

peopledata
# RULE SET 3 : The status should be "married", "single" or "widowed
query3 <- "SELECT * FROM peopledata WHERE Status = 'single' OR Status = 'married' OR Status = 'widowed'"
sqldf(query3)

# RULE SET 4 : If age is less than 18 the agegroup should be child, 
# if age is between 18 and 65 the agegroup should be adult, if age 
# is more than  65 the agegroup should be elderly.
query4 <- "SELECT * FROM peopledata WHERE Age < 18  AND Agegroup = 'child' OR Age >= 18 AND Age <= 65 AND Agegroup = 'adult' OR Age > 65 AND Agegroup = 'elderly' "
sqldf(query4)

# Summarize the results
mean(peopledata$Age, na.rm = TRUE)
mean(peopledata$Height, na.rm = TRUE)
mean(peopledata$Yearsmarried, na.rm = TRUE)

median(peopledata$Age, na.rm = TRUE)
median(peopledata$Height, na.rm = TRUE)
median(peopledata$Yearsmarried, na.rm = TRUE)

var(peopledata$Age, na.rm = TRUE)
var(peopledata$Height, na.rm = TRUE)
var(peopledata$Yearsmarried, na.rm = TRUE)

sd(peopledata$Age, na.rm = TRUE)
sd(peopledata$Height, na.rm = TRUE)
sd(peopledata$Yearsmarried, na.rm = TRUE)

mad(peopledata$Age, na.rm = TRUE)
mad(peopledata$Height, na.rm = TRUE)
mad(peopledata$Yearsmarried, na.rm = TRUE)

min(peopledata$Age, na.rm = TRUE)
min(peopledata$Height, na.rm = TRUE)
min(peopledata$Yearsmarried, na.rm = TRUE)

max(peopledata$Age, na.rm = TRUE)
max(peopledata$Height, na.rm = TRUE)
max(peopledata$Yearsmarried, na.rm = TRUE)

quantile(peopledata$Age, na.rm = TRUE)
quantile(peopledata$Height, na.rm = TRUE)
quantile(peopledata$Yearsmarried, na.rm = TRUE)

IQR(peopledata$Age, na.rm = TRUE)
IQR(peopledata$Height, na.rm = TRUE)
IQR(peopledata$Yearsmarried, na.rm = TRUE)

fivenum(peopledata$Age, na.rm = TRUE)
fivenum(peopledata$Height, na.rm = TRUE)
fivenum(peopledata$Yearsmarried, na.rm = TRUE)

# Summary of the dataset
summary(peopledata)

# scatter plot
with(peopledata, plot(Age, Height, main="Age versus Height", 
                      xlab="Age", ylab="Height", col="blue", pch=18, 
                      log="xy"))

#lattice
library(lattice)
(scatter_lattice<- xyplot(Age~Height, peopledata,main="Age versus Height" , xlab="Age", 
                          ylab="Height", col= "blue", pch=18,scales = list(log=TRUE))) 

(scatter_latice_update <- update(scatter_lattice, col = "violet", pch = 20))

# ggplot
library(ggplot2)

ggplot(peopledata, aes(x = Age, y = Height)) + 
  geom_point(size = 0.5) + 
  ggtitle("Age versus Height") + 
  xlab("Age") + ylab("Height")
