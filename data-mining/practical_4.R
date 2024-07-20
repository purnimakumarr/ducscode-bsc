setwd("C:\\Users\\purnima\\OneDrive\\Documents\\RPrograms")
getwd()
dir()
data(Titanic)
str(Titanic)
View(Titanic)

# read AR data converted from titanic data from website http://www.cs.toronto.edu/~delve/
#data/titanic/desc.html
titan <- read.table("./dataset.data", header=F)
View(titan)

names(titan) <- c("Class","Age", "Sex", "Survived")
View(titan)

install.packages("arules")
library(arules)
search()

# find association rules with default settings
#supp=0.1, ; 2) conf=0.8, 3) maxlen=10,
#rules.all <- apriori(titanic.raw)
rules.all <- apriori(titan)
quality(rules.all) <- round(quality(rules.all), digits=3)
rules.all

inspect(rules.all)

#plotting AR
install.packages("arulesViz")
library(arulesViz)
search()

plot(rules.all)
plot(rules.all, method="grouped")

# Minimum support is 50% & Minimum confidence is 75%
rules <- apriori(titan, parameter = list(supp = 0.5, conf = 0.75))
quality(rules) <- round(quality(rules), digits=3)
rules

inspect(rules)

# Show the top 5 rules, but only 2 digits
options(digits=2)
inspect(rules[1:5])
summary(rules)  #summary statistics

# Minimum support is 60% & Minimum confidence is 60%
rules1 <- apriori(titan, parameter = list(supp = 0.6, conf = 0.6))
quality(rules1) <- round(quality(rules1), digits=3)
rules1

inspect(rules1)

# Show the top 5 rules, but only 2 digits
options(digits=2)
inspect(rules1[1:5])
summary(rules1)  #summary statistics
