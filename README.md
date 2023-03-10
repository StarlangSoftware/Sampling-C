Sampling Strategies
============

## K-Fold cross-validation
In K-fold cross-validation, the aim is to generate K training/validation set pair, where training and validation sets on fold i do no overlap. First, we divide the dataset X into K parts as X<sub>1</sub>; X<sub>2</sub>; ... ; X<sub>K</sub>. Then for each fold i, we use X<sub>i</sub> as the validation set and the remaining as the training set.

Possible values of K are 10 or 30. One extreme case of K-fold cross-validation is leave-one-out, where K = N and each validation set has only one instance.
If we have more computation power, we can have multiple runs of K-fold cross-validation, such as 10 x 10 cross-validation or 5 x 2 cross-validation.

## Bootstrapping

If we have very small datasets, we do not insist on the non-overlap of training and validation sets. In bootstrapping, we generate K multiple training sets, where each training set contains N examples (like the original dataset). To get N examples, we draw examples with replacement. For the validation set, we use the original dataset. The drawback of bootstrapping is that the bootstrap samples overlap more than the cross-validation sample, hence they are more dependent.

Video Lectures
============

[<img src="https://github.com/StarlangSoftware/Sampling/blob/master/video.jpg" width="50%">](https://youtu.be/wijWOiv70nE)

For Developers
============

You can also see [Java](https://github.com/starlangsoftware/Sampling), [Python](https://github.com/starlangsoftware/Sampling-Py), 
[Cython](https://github.com/starlangsoftware/Sampling-Cy), [Swift](https://github.com/starlangsoftware/Sampling-Swift), 
[Js](https://github.com/starlangsoftware/Sampling-Js), [C#](https://github.com/starlangsoftware/Sampling-CS), 
or [C++](https://github.com/starlangsoftware/Sampling-CPP) repository.

## Requirements

* C Editor
* [Git](#git)

### Git

Install the [latest version of Git](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git).

## Download Code

In order to work on code, create a fork from GitHub page. 
Use Git for cloning the code to your local or below line for Ubuntu:

	git clone <your-fork-git-link>

A directory called Sampling-C will be created. Or you can use below link for exploring the code:

	git clone https://github.com/starlangsoftware/Sampling-C.git

## Open project with Rider IDE

To import projects from Git with version control:

* Open Rider IDE, select Get From Version Control.

* In the Import window, click URL tab and paste github URL.

* Click open as Project.

Result: The imported project is listed in the Project Explorer view and files are loaded.


## Compile

**From IDE**

After being done with the downloading and opening project, select **Build Solution** option from **Build** menu. After compilation process, user can run Sampling-CS.

Detailed Description
============

+ [CrossValidation](#crossvalidation)
+ [Bootstrap](#bootstrap)
+ [KFoldCrossValidation](#kfoldcrossvalidation)
+ [StratifiedKFoldCrossValidation](#stratifiedkfoldcrossvalidation)

## CrossValidation

k. e??itim k??mesini elde etmek i??in

	ArrayList<T> GetTrainFold(int k)

k. test k??mesini elde etmek i??in

	ArrayList<T> GetTestFold(int k)

## Bootstrap

Bootstrap i??in BootStrap s??n??f??

	Bootstrap(List<T> instanceList, int seed)

??rne??in elimizdeki veriler a adl?? ArrayList'te olsun. Bu veriler ??st??nden bir bootstrap 
??rneklemi tan??mlamak i??in (5 burada rasgelelik getiren seed'i g??stermektedir. 5 
de??i??tirilerek farkl?? samplelar elde edilebilir)

	bootstrap = Bootstrap(a, 5);

ard??ndan ??retilen sample'?? ??ekmek i??in ise

	sample = bootstrap.getSample();

yaz??l??r.

## KFoldCrossValidation

K kat ??apraz ge??erleme i??in KFoldCrossValidation s??n??f??

	KFoldCrossValidation(List<T> instanceList, int K, int seed)

??rne??in elimizdeki veriler a adl?? ArrayList'te olsun. Bu veriler ??st??nden 10 kat ??apraz 
ge??erleme yapmak i??in (2 burada rasgelelik getiren seed'i g??stermektedir. 2 
de??i??tirilerek farkl?? samplelar elde edilebilir)

	kfold = KFoldCrossValidation(a, 10, 2);

ard??ndan yukar??da belirtilen getTrainFold ve getTestFold metodlar?? ile s??ras??yla i. e??itim
ve test k??meleri elde edilebilir. 

## StratifiedKFoldCrossValidation

Stratified K kat ??apraz ge??erleme i??in StratifiedKFoldCrossValidation s??n??f??

	StratifiedKFoldCrossValidation(List<T>[] instanceLists, int K, int seed)

??rne??in elimizdeki veriler a adl?? ArrayList of listte olsun. Stratified bir ??apraz 
ge??erlemede s??n??flara ait veriler o s??n??f??n oran??nda temsil edildikleri i??in her bir 
s??n??fa ait verilerin ayr?? ayr?? ArrayList'te olmalar?? gerekmektedir. Bu veriler ??st??nden 
30 kat ??apraz ge??erleme yapmak i??in (4 burada rasgelelik getiren seed'i g??stermektedir. 4 
de??i??tirilerek farkl?? samplelar elde edilebilir)

	stratified = StratifiedKFoldCrossValidation(a, 30, 4);

ard??ndan yukar??da belirtilen getTrainFold ve getTestFold metodlar?? ile s??ras??yla i. e??itim
ve test k??meleri elde edilebilir. 

