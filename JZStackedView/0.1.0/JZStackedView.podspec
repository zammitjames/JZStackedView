#
# Be sure to run `pod lib lint JZStackedView.podspec' to ensure this is a
# valid spec and remove all comments before submitting the spec.
#
# Any lines starting with a # are optional, but encouraged
#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = "JZStackedView"
  s.version          = "0.1.0"
  s.summary          = 'JZStackedView is a 3D stacked view based library allowing user create a more modern carousel.'
  s.homepage         = "https://github.com/zammitjames/JZStackedView"
  s.license          = { :type => 'BSD' }
  s.author           = { "James Zammit" => "jameszammit@gmail.com" }
  s.source           = { :git => "https://github.com/zammitjames/JZStackedView.git", :tag => s.version.to_s }

  s.platform     = :ios, '7.0'
  s.requires_arc = true

  s.source_files = 'Pod/Classes/JZStackedView.{h,m}'

end
