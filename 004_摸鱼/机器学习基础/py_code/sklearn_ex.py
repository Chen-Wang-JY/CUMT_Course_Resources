from sklearn.datasets import load_iris
from sklearn.decomposition import PCA


from sklearn import model_selection
import sklearn.metrics as metrics

data=load_iris()
iris_y=data.target
iris_x=data.data

pca=PCA(n_components=2)
reduced_x=pca.fit_transform(iris_x)

#X_train,X_test,y_train,y_test=model_selection.train_test_split(iris_x,iris_y,random_state=1,test_size=0.3)
X_train,X_test,y_train,y_test=model_selection.train_test_split(reduced_x,iris_y,random_state=1,test_size=0.3)


from sklearn import svm
classifier=svm.SVC(kernel='rbf')
classifier.fit(X_train,y_train.ravel())
y_predict = classifier.predict(X_test)


#print(metrics.classification_report(y_test, y_predict))
#print(metrics.confusion_matrix(y_test,y_predict))
print(metrics.precision_score(y_test,y_predict,average=None))
print(metrics.recall_score(y_test,y_predict,average=None))
print(metrics.f1_score(y_test,y_predict,average=None))

from sklearn.neighbors import KNeighborsClassifier
#k近邻算法
knn = KNeighborsClassifier(n_neighbors=3)
knn.fit(X_train, y_train)

y_predict = knn.predict(X_test)

print(metrics.precision_score(y_test,y_predict,average=None))
print(metrics.recall_score(y_test,y_predict,average=None))
print(metrics.f1_score(y_test,y_predict,average=None))

from sklearn.discriminant_analysis import LinearDiscriminantAnalysis
clf = LinearDiscriminantAnalysis()
clf.fit(X_train, y_train)

y_predict = clf.predict(X_test)

print(metrics.precision_score(y_test,y_predict,average=None))
print(metrics.recall_score(y_test,y_predict,average=None))
print(metrics.f1_score(y_test,y_predict,average=None))
