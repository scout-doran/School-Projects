<<<<<<< HEAD
# Code modified by: Dip, Scout, Tony, Tay

#Make sure to change code as much as you can if you work on this 

library(readr)
library(caret) 
library(FNN)
library(doParallel)


train <- read_csv("train.csv")
test <- read_csv("test.csv")

#Exploratory Data Analysis 
dim(train)
dim(test)

#Converts the label into a factor data type 
#Transfrom the label column to a factor 
train[, 1] <- as.factor(train[, 1]$label) 


train_orig <- train
test_orig <- test

#Drop columns with near zero variance or contains 0 for all observations
nzv.data <- nearZeroVar(train, saveMetrics = TRUE)
drop.cols <- rownames(nzv.data)[nzv.data$nzv == TRUE]
train <- train[,!names(train) %in% drop.cols]
test <- test[,!names(test) %in% drop.cols]

#Set or query graphical parameters 
par(mfrow = c(2, 5), pty = "s", mar = c(1, 1, 1, 1), xaxt = "n", yaxt = "n")
images_digits_0_9 <- array(dim = c(10, 28 * 28))
for (digit in 0:9) {
  images_digits_0_9[digit + 1, ] <- apply(train_orig[train_orig[, 1] == digit, -1], 2, sum)
  images_digits_0_9[digit + 1, ] <- images_digits_0_9[digit + 1, ]/max(images_digits_0_9[digit + 1, ]) * 255
  z <- array(images_digits_0_9[digit + 1, ], dim = c(28, 28))
  z <- z[, 28:1]
  image(1:28,1:28, z,xlab = "", ylab="",col = gray((0:255)/255))
}

table_1 <- table(train$label)
table_1.df <- as.data.frame(table_1)
ggplot(table_1.df, aes(x=Var1, y=Freq, fill=Var1)) + geom_bar(stat="identity") + labs(y="Proportion", x = "Numbers", fill="Number")
#barplot(table_1, main="Digits in Dataset", xlab="Numbers", ylab="Number of digits", ylim=c(0,5000), col=rainbow(n=7))


#Only 10 percent of the data has been used
set.seed(43210)
trainIndex <- createDataPartition(train$label, p = 0.1, list = FALSE, times = 1)
allindices <- c(1:42000)
training <- train[trainIndex,]
validating <- train[-trainIndex,]
vali0_index <- allindices[! allindices %in% trainIndex]
validIndex <- createDataPartition(validating$label, p = 0.11, list = FALSE, times = 1)
validating <- validating[validIndex,]

rotate <- function(x) t(apply(x, 2, rev))

power = 3
Contrast <- function (DATASET, POWER) {
  outDATASET <- cbind(DATASET$label, as.data.frame((DATASET[,-1]/255)^(POWER)*255))
  names(outDATASET)[1] <- "label"  
  outDATASET
}

train_orig_low_contrast <- Contrast(train_orig, 1/power) 
train_orig_high_contrast <- Contrast(train_orig, power) 

plotIndex = 4
par(mfrow = c(1, 3), pty ='s')
m = rotate(matrix(unlist(train_orig_low_contrast[plotIndex,-1]),ncol = 28,byrow = T))
image(m,col=gray((0:255)/255), main = "lower contrast")
m = rotate(matrix(unlist(train_orig[plotIndex,-1]),ncol = 28,byrow = T))
image(m,col=gray((0:255)/255), main = "original")
m = rotate(matrix(unlist(train_orig_high_contrast[plotIndex,-1]),ncol = 28,byrow = T))
image(m,col=gray((0:255)/255), main = "higher contrast")

training2   <- Contrast(training, 1/power)
training3   <- Contrast(training,   power)
validating2 <- Contrast(validating, 1/power)
validating3 <- Contrast(validating, power)
training4 <- rbind(training, training2, training3)

registerDoParallel(3)
ctrl <- trainControl(method="repeatedcv",repeats = 1, number = 4, verboseIter = T, allowParallel = T)
knnFit <- train(label ~ ., data = training, method = "knn", trControl = ctrl)
plot(knnFit)



fnn.kd1 <- FNN::knn(training[,-1], validating[,-1], training$label, k=5, algorithm = c("kd_tree"))
fnn.kd.pred1 <- as.numeric(fnn.kd1)-1
fnn.kd.pred1 <- as.factor(fnn.kd.pred1)

fnn.kd2 <- FNN::knn(training2[,-1], validating2[,-1], training2$label, k=5, algorithm = c("kd_tree"))
fnn.kd.pred2 <- as.numeric(fnn.kd2)-1
fnn.kd.pred2 <- as.factor(fnn.kd.pred2)

fnn.kd3 <- FNN::knn(training3[,-1], validating3[,-1], training3$label, k=5, algorithm = c("kd_tree"))
fnn.kd.pred3 <- as.numeric(fnn.kd3)-1
fnn.kd.pred3 <- as.factor(fnn.kd.pred3)


#Need to comment about accuracy, F1 score stuffs
confusionMatrix(fnn.kd.pred1, validating$label)
confusionMatrix(fnn.kd.pred2, validating$label)
confusionMatrix(fnn.kd.pred3, validating$label)

fnn.kd4 <- FNN::knn(training4[,-1], validating2[,-1], training4$label, k=5, algorithm = c("kd_tree"))
fnn.kd.pred4 <- as.numeric(fnn.kd4)-1
fnn.kd.pred4 <- as.factor(fnn.kd.pred4)

confusionMatrix(fnn.kd.pred4, validating2$label)

train2 <- Contrast (train, 1/power)
train3 <- Contrast (train,   power)
test4  <- as.data.frame((test/255)^(1/power)*255)

train4 <- rbind(train, train2, train3)

set.seed(43210)
fnn.kd_all <- FNN::knn(train4[,-1], test4, train4$label, k=5, algorithm = c("kd_tree"))
fnn.kd.pred_all <- as.numeric(fnn.kd_all)-1

preds_FNN <- data.frame(FNN = fnn.kd.pred_all)
FNN_Submit = data.frame(ImageId = seq(1,28000), label=preds_FNN)
write.csv(FNN_Submit, file = "FNN_Submit.csv", row.names=F)

=======
# Code modified by: Dip, Scout, Tony, Tay

library(readr)
library(caret) 
library(FNN)
library(doParallel)

#load data sets
train <- read_csv("train.csv")
test <- read_csv("test.csv")

#Exploratory Data Analysis
#dim determines size
dim(train)
dim(test)

#Converts the label into a factor data type 
train[, 1] <- as.factor(train[, 1]$label) 

#remove columns that contain 0 using drop
train_orig <- train
test_orig <- test
nzv.data <- nearZeroVar(train, saveMetrics = TRUE)
drop.cols <- rownames(nzv.data)[nzv.data$nzv == TRUE]
train <- train[,!names(train) %in% drop.cols]
test <- test[,!names(test) %in% drop.cols]

#Visualization / EDA
par(mfrow = c(4, 3), pty = "s", mar = c(1, 1, 1, 1), xaxt = "n", yaxt = "n")
images_digits_0_9 <- array(dim = c(10, 28 * 28))
for (digit in 0:9) {
  images_digits_0_9[digit + 1, ] <- apply(train_orig[train_orig[, 1] == digit, -1], 2, sum)
  images_digits_0_9[digit + 1, ] <- images_digits_0_9[digit + 1, ]/max(images_digits_0_9[digit + 1, ]) * 255
  z <- array(images_digits_0_9[digit + 1, ], dim = c(28, 28))
  z <- z[, 28:1]
  image(1:28, 1:28, z, main = digit, col = gray((0:255)/255))
}

#1st barplot
table_1 <- table(train$label)
barplot(table_1, main="Digits in Dataset", xlab="Numbers", ylab="Number of digits", ylim=c(0,5000), col=rainbow(n=7))


set.seed(43210)
trainIndex <- createDataPartition(train$label, p = 0.1, list = FALSE, times = 1)
allindices <- c(1:42000)
training <- train[trainIndex,]
validating <- train[-trainIndex,]
vali0_index <- allindices[! allindices %in% trainIndex]
validIndex <- createDataPartition(validating$label, p = 0.11, list = FALSE, times = 1)
validating <- validating[validIndex,]

rotate <- function(x) t(apply(x, 2, rev))

power = 3
Contrast <- function (DATASET, POWER) {
  outDATASET <- cbind(DATASET$label, as.data.frame((DATASET[,-1]/255)^(POWER)*255))
  names(outDATASET)[1] <- "label"  
  outDATASET
}

train_orig_low_contrast <- Contrast(train_orig, 1/power) 
train_orig_high_contrast <- Contrast(train_orig, power) 

plotIndex = 4
par(mfrow = c(1, 3), pty ='s')
m = rotate(matrix(unlist(train_orig_low_contrast[plotIndex,-1]),ncol = 28,byrow = T))
image(m,col=gray((0:255)/255), main = "lower contrast")
m = rotate(matrix(unlist(train_orig[plotIndex,-1]),ncol = 28,byrow = T))
image(m,col=gray((0:255)/255), main = "original")
m = rotate(matrix(unlist(train_orig_high_contrast[plotIndex,-1]),ncol = 28,byrow = T))
image(m,col=gray((0:255)/255), main = "higher contrast")

training2   <- Contrast(training, 1/power)
training3   <- Contrast(training,   power)
validating2 <- Contrast(validating, 1/power)
validating3 <- Contrast(validating, power)
training4 <- rbind(training, training2, training3)


#K-Nearest Neighbor (KNN)
registerDoParallel(3)
ctrl <- trainControl(method="repeatedcv",repeats = 1, number = 4, verboseIter = T, allowParallel = T)
knnFit <- train(label ~ ., data = training, method = "knn", trControl = ctrl)
plot(knnFit)

#Fastest K- Nearest Neighbor (FNN)
#K = 5
fnn.kd1 <- FNN::knn(training[,-1], validating[,-1], training$label, k=5, algorithm = c("kd_tree"))
fnn.kd.pred1 <- as.numeric(fnn.kd1)-1
fnn.kd.pred1 <- as.factor(fnn.kd.pred1)

fnn.kd2 <- FNN::knn(training2[,-1], validating2[,-1], training2$label, k=5, algorithm = c("kd_tree"))
fnn.kd.pred2 <- as.numeric(fnn.kd2)-1
fnn.kd.pred2 <- as.factor(fnn.kd.pred2)

fnn.kd3 <- FNN::knn(training3[,-1], validating3[,-1], training3$label, k=5, algorithm = c("kd_tree"))
fnn.kd.pred3 <- as.numeric(fnn.kd3)-1
fnn.kd.pred3 <- as.factor(fnn.kd.pred3)

#Displays accuracy and F1 score, etc.
confusionMatrix(fnn.kd.pred1, validating$label)
confusionMatrix(fnn.kd.pred2, validating$label)
confusionMatrix(fnn.kd.pred3, validating$label)


#FNN
#Use validating2 because it has the lowest contrast
fnn.kd4 <- FNN::knn(training4[,-1], validating2[,-1], training4$label, k=5, algorithm = c("kd_tree"))
fnn.kd.pred4 <- as.numeric(fnn.kd4)-1
fnn.kd.pred4 <- as.factor(fnn.kd.pred4)
#Confusion Matrix
confusionMatrix(fnn.kd.pred4, validating2$label)


train2 <- Contrast (train, 1/power)
train3 <- Contrast (train,   power)
test4  <- as.data.frame((test/255)^(1/power)*255)

train4 <- rbind(train, train2, train3)

set.seed(43210)
fnn.kd_all <- FNN::knn(train4[,-1], test4, train4$label, k=5, algorithm = c("kd_tree"))
fnn.kd.pred_all <- as.numeric(fnn.kd_all)-1

preds_FNN <- data.frame(FNN = fnn.kd.pred_all)
FNN_Submit = data.frame(ImageId = seq(1,28000), label=preds_FNN)
write.csv(FNN_Submit, file = "FNN_Submit.csv", row.names=F)

>>>>>>> 7a73466cad5e2cdfbba81121e380314e2e45e2c4
