# JZStackedView

[![CI Status](https://img.shields.io/teamcity/http/teamcity.jetbrains.com/s/bt345.svg)](https://travis-ci.org/github.com)
[![Version](https://img.shields.io/cocoapods/v/JZStackedView.svg?style=flat)](http://cocoapods.org/pods/JZStackedView)
[![License](https://img.shields.io/cocoapods/l/JZStackedView.svg?style=flat)](http://cocoapods.org/pods/JZStackedView)
[![Platform](https://img.shields.io/cocoapods/p/JZStackedView.svg?style=flat)](http://cocoapods.org/pods/JZStackedView)

![](https://github.com/zammitjames/JZStackedView/blob/master/Demo.gif)

## Installation

JZStackedView is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod "JZStackedView"
```
or install manually by downloading the files from GitHub and then use
```
#import "JZStackedView.h"
```

## Usage

######To run the example project, clone the repo, and run `pod install` from the Example directory first.
-

Add the below reference to the @interface method in the header file(.h)
```
@property (nonatomic, strong) IBOutlet JZ *JZStackedView;
```

Initialize the JZStackedView in the Implementation File (.m)
```
_JZStackedView = [[JZ alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height * 0.75)];
 _JZStackedView.delegate = self;
_JZStackedView.dataSource = self;
[_JZStackedView setCenter:CGPointMake(self.view.frame.size.width * 0.5, self.view.frame.size.height * 0.5)];
_JZStackedView.bounces = YES;
_JZStackedView.scrollSpeed = 0.85f;
_JZStackedView.vertical = YES;
_JZStackedView.bounceDistance = 0.4f;
_JZStackedView.pagingEnabled = YES;
_JZStackedView.ignorePerpendicularSwipes = YES;
[self.view addSubview:_JZStackedView];
```

## Requirements
  * iOS 7.0 or higher
  * ARC

## Author

James Zammit, jameszammit@gmail.com

## License

JZStackedView is available under the MIT license. See the LICENSE file for more info.
