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
```ObjC
#import "JZStackedView.h"
```

## Usage

######To run the example project, clone the repo, and run `pod install` from the Example directory first.
-

Add the below reference to the @interface method in the header file(.h)
```ObjC
@property (nonatomic, strong) IBOutlet JZ *JZStackedView;
```

Initialize the JZStackedView in the Implementation File (.m)
```ObjC
self.JZStackedView = [[JZ alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width,
self.view.frame.size.height * 0.75)];
[self.JZStackedView setCenter:CGPointMake(self.view.frame.size.width * 0.5, self.view.frame.size.height * 0.5)];
self.JZStackedView.delegate = self;
self.JZStackedView.dataSource = self;
[self.view addSubview:self.JZStackedView];

self.JZStackedView.bounces = YES;
self.JZStackedView.scrollSpeed = 0.85f;
self.JZStackedView.vertical = YES;
self.JZStackedView.bounceDistance = 0.4f;
self.JZStackedView.pagingEnabled = YES;
self.JZStackedView.ignorePerpendicularSwipes = YES;

```

Listen to Delegate Methods
```ObjC
- (NSInteger)numberOfItemsInJZStackedView:(JZ *)JZStackedView;
- (UIView *)JZStackedView:(JZ *)JZStackedView viewForItemAtIndex:(NSInteger)index reusingView:(UIView *)view;
```

## Requirements
  * iOS 7.0 or higher
  * ARC

## Author

James Zammit, jameszammit@gmail.com

## License

JZStackedView is available under the MIT license. See the LICENSE file for more info.
