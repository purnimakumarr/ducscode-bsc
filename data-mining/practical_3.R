setwd("C:\\Users\\purnima\\OneDrive\\Documents\\RPrograms")

wine <- file.choose()
winedata <- read.csv(wine, header=FALSE, sep=",")
winedata

# check if the mean is standardized
mean(winedata$V1, na.rm=TRUE)
sd(winedata$v1, na.rm=TRUE)

mean(winedata$V2, na.rm=TRUE)
sd(winedata$v2, na.rm=TRUE)

mean(winedata$V3, na.rm=TRUE)
sd(winedata$v3, na.rm=TRUE)

mean(winedata$V4, na.rm=TRUE)
sd(winedata$v4, na.rm=TRUE)

mean(winedata$V5, na.rm=TRUE)
sd(winedata$v5, na.rm=TRUE)

mean(winedata$V6, na.rm=TRUE)
sd(winedata$v6, na.rm=TRUE)

mean(winedata$V7, na.rm=TRUE)
sd(winedata$v7, na.rm=TRUE)

mean(winedata$V8, na.rm=TRUE)
sd(winedata$v8, na.rm=TRUE)

mean(winedata$V9, na.rm=TRUE)
sd(winedata$v9, na.rm=TRUE)

mean(winedata$V10, na.rm=TRUE)
sd(winedata$v10, na.rm=TRUE)

mean(winedata$V11, na.rm=TRUE)
sd(winedata$v11, na.rm=TRUE)

mean(winedata$V12, na.rm=TRUE)
sd(winedata$v12, na.rm=TRUE)

mean(winedata$V13, na.rm=TRUE)
sd(winedata$v13, na.rm=TRUE)

mean(winedata$V14, na.rm=TRUE)
sd(winedata$v14, na.rm=TRUE)

# as observed all 14 attributes have non-standardized mean
# therefore, we standardize the attributes
winedata$v1 <- scale(winedata$V1, center=TRUE, scale=TRUE)
winedata$v2 <- scale(winedata$V2, center=TRUE, scale=TRUE)
winedata$v3 <- scale(winedata$V3, center=TRUE, scale=TRUE)
winedata$v4 <- scale(winedata$V4, center=TRUE, scale=TRUE)
winedata$v5 <- scale(winedata$V5, center=TRUE, scale=TRUE)
winedata$v6 <- scale(winedata$V6, center=TRUE, scale=TRUE)
winedata$v7 <- scale(winedata$V7, center=TRUE, scale=TRUE)
winedata$v8 <- scale(winedata$V8, center=TRUE, scale=TRUE)
winedata$v9 <- scale(winedata$V9, center=TRUE, scale=TRUE)
winedata$v10 <- scale(winedata$V10, center=TRUE, scale=TRUE)
winedata$v11 <- scale(winedata$V11, center=TRUE, scale=TRUE)
winedata$v12 <- scale(winedata$V12, center=TRUE, scale=TRUE)
winedata$v13 <- scale(winedata$V13, center=TRUE, scale=TRUE)
winedata$v14 <- scale(winedata$V14, center=TRUE, scale=TRUE)

mean(winedata$V1, na.rm=TRUE)
sd(winedata$v1, na.rm=TRUE)

mean(winedata$V6, na.rm=TRUE)
sd(winedata$v6, na.rm=TRUE)

mean(winedata$V12, na.rm=TRUE)
sd(winedata$v12, na.rm=TRUE)