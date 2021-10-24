library(readr)
library(caret) 
library(e1071)

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
#20 percent of the data 
trainIndex <- createDataPartition(train$label, p = 0.2, list = FALSE, times = 1)
allindices <- c(1:42000)
training <- train[trainIndex,]
validating <- train[-trainIndex,]
vali0_index <- allindices[! allindices %in% trainIndex]
validIndex <- createDataPartition(validating$label, p = 0.2, list = FALSE, times = 1)
validating <- validating[validIndex,]

nbmodel <- naiveBayes(label~., training, method="class")

nbpred <- predict(nbmodel, validating, type="class")
confusionMatrix(validating$label, nbpred)

prediction_submission <- predict(nbmodel, test)
NB_submit <- data.frame(ImageId = seq(1,28000), label = prediction_submission)
write.csv(NB_submit, file="Naive-Baiyes.csv", row.names=F)

