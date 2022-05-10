(window.webpackJsonp=window.webpackJsonp||[]).push([[97],{"1ah5":function(module,e,t){"use strict";var n=t("q1tI"),a=t.n(n),i=t("oX1x"),r=t("Q/5i"),c=function QuizGradeDisclaimer(e){var t=e.courseSlug;if(t)return a.a.createElement(i.a,{courseSlug:t},function(e){var t=e.notifications;if(null==t?void 0:t.some(function(e){return"gradeDisclaimerMessage"===e.typeName}))return a.a.createElement(r.a,null);return null});return null};e.a=c},"2S0G":function(module,e,t){"use strict";var n=t("AeFk"),a=t("q1tI"),i=t.n(a),r=t("kvW3"),c=t("8Hdl"),o=t("/Fji"),s=t("TpV6"),u=t("vrZb"),l=t.n(u),d={titleContainer:function titleContainer(e){return Object(n.c)({margin:e.spacing(12,0)})},description:function description(e){return Object(n.c)({marginBottom:e.spacing(4)})}},m=function LearningObjectivesWithItemsList(e){var t=e.learningObjectives;return Object(n.d)("div",null,null==t?void 0:t.map(function(e,t){var a=e.id,i=e.description,u=e.computedItems;return Object(n.d)("div",{key:"learning-objective-".concat(a)},Object(n.d)(o.a,{key:a,title:Object(n.d)("div",{css:d.titleContainer},Object(n.d)(c.a,{variant:"h2semibold",component:"h3",css:d.description},i),Object(n.d)(c.a,{variant:"body1"},Object(n.d)(r.b,{message:l()("{numItems, plural, =0 {Nothing} one {# material} other {# materials}} to review"),numItems:(null==u?void 0:u.length)||0}))),isCollapsible:!!(null==u?void 0:u.length),collapsibleIconTitle:u&&(null==u?void 0:u.length)>1?l()("Materials to review"):l()("Material to review"),startCollapsed:t>0||!(null==u?void 0:u.length)},null==u?void 0:u.map(function(e){return Object(n.d)("div",{key:"learning-objective-item-".concat(a,"-").concat(e.id)},Object(n.d)(s.a,{computedItem:e}))})))}))};e.a=m},"2iEy":function(module,e,t){"use strict";t.d(e,"a",function(){return O}),t.d(e,"d",function(){return f}),t.d(e,"c",function(){return h});var n=t("lSNA"),a=t.n(n),i=t("J2iB"),r=t.n(i),c=t("q1tI"),o=t.n(c),s=t("AeFk"),u=t("763+"),l=t("8Hdl"),d=t("PSZr"),m=t("IXUt"),b=t("d3Ej"),p=t.n(b),v=function getRootStyles(e,t){return Object(s.c)(a()({padding:e.spacing(24,0),borderBottom:"1px solid ".concat(e.palette.gray[300]),display:"flex",justifyContent:"space-between",position:"relative",flexWrap:"wrap",flexDirection:t?"row-reverse":"row",":last-child":{paddingBottom:e.spacing(48)}},e.breakpoints.down("sm"),{flexDirection:"column"}))},g=function statusIcon(e){return Object(s.c)({marginRight:e.spacing(8),lineHeight:2})},j=function stepTitle(e){return Object(s.c)({display:"flex",marginBottom:e.spacing(8)})},O={check:"check",warning:"warning"},f=function getStatusIconTypeForGradeRow(e,t,n){if(r()(e))return null;if(!e&&(!t||n&&t))return O.warning;return O.check},h=function getStatusIconTitleForGradeRow(e,t){if(r()(e))return;if(!e&&!t)return p()("Activity Incomplete");return p()("Activity Completed")},y=function CoverPageRow(e){var t=e.stepTitle,n=e.stepDetails,a=e.rightSideView,i=e.statusIconType,r=e.statusIconTitle,c=Object(u.a)();return Object(s.d)("div",{css:v(c,!t)},t&&Object(s.d)("div",null,Object(s.d)("div",{css:j(c)},i&&Object(s.d)("div",{css:g(c),"aria-hidden":"true"},i===O.check&&Object(s.d)(d.a,{size:"medium",color:"success",title:r}),i===O.warning&&Object(s.d)(m.a,{size:"medium",color:"error",title:r})),Object(s.d)(l.a,{variant:"h3bold"},t)),Object(s.d)("div",null,n)),Object(s.d)("div",null,a))};e.b=y},"5qmR":function(module,exports,e){},"8mOo":function(module,e,t){"use strict";var n=t("8cuT"),a=t("MnCE"),i=Object(a.compose)(Object(n.a)(["CourseStore"],function(e,t){var n,a=e.CourseStore,i=t.itemMetadata,r,c,o=a.getMaterials().getNeighbors(i).nextItemMetadataOrItemGroup;return{nextItemUrl:null!==(n=null==o?void 0:o.getLink())&&void 0!==n?n:""}}));e.a=i},FkXZ:function(module,exports,e){var t=e("5qmR"),n;"string"==typeof t&&(t=[[module.i,t,""]]);var a={transform:void 0},i=e("aET+")(t,a);t.locals&&(module.exports=t.locals)},NXzb:function(module,e,t){"use strict";var n=t("VkAN"),a=t.n(n),i=t("UB5X"),r=t.n(i),c=t("q1tI"),o=t.n(c),s=t("AeFk"),u=t("763+"),l=t("8Hdl"),d=t("ZJgU"),m=t("hbUA"),b=t("kvW3"),p=t("bOpO"),v=t("d3Ej"),g=t.n(v),j=t("PB6g");function _templateObject5(){var e=a()(["\n        padding: ",";\n      "]);return _templateObject5=function _templateObject5(){return e},e}function _templateObject4(){var e=a()(["\n          display: flex;\n        "]);return _templateObject4=function _templateObject4(){return e},e}function _templateObject3(){var e=a()(["\n    margin-right: ",";\n    "," {\n      margin-bottom: ",";\n      margin-top: ",";\n    }\n  "]);return _templateObject3=function _templateObject3(){return e},e}function _templateObject2(){var e=a()(["\n    display: flex;\n    flex-direction: column;\n    align-items: flex-start;\n    justify-content: space-between;\n    "," {\n      margin-top: ",";\n    }\n    margin-bottom: ",";\n  "]);return _templateObject2=function _templateObject2(){return e},e}function _templateObject(){var e=a()(["\n    display: flex;\n    justify-content: space-between;\n    min-width: 300px;\n    min-height: 48px;\n    padding-left: ",";\n    border-left: 1px solid ",";\n    "," {\n      border: none;\n      padding-left: 0;\n      flex-direction: column;\n      margin-left: 0;\n      margin-top: ",";\n    }\n  "]);return _templateObject=function _templateObject(){return e},e}var O=function root(e){return Object(s.c)(_templateObject(),e.spacing(24),e.palette.gray[300],e.breakpoints.down("sm"),e.spacing(24))},f=function viewFeedbackButton(e){return Object(s.c)(_templateObject2(),e.breakpoints.down("sm"),e.spacing(24),e.spacing(8))},h=function gradeContainer(e){return Object(s.c)(_templateObject3(),e.spacing(16),e.breakpoints.down("sm"),e.spacing(8),e.spacing(8))},y=function CoverPageRowRightSideGrade(e){var t=e.itemGrade,n=e.computedScore,a=e.maxScore,i=e.viewFeedback,c=e.isViewFeedbackButtonLinkStyle,o=e.isCumulativeGraded,m=e.reviewsExpected,b=void 0===m?0:m,p=e.reviewsReceived,v=void 0===p?0:p,j=e.showKeepHighScoreMsg,y=void 0===j||j,w=e.isRequired,k=void 0!==w&&w,C=Object(u.a)(),x=t||{},I=x.grade,L=x.isPassed,P=r()(I)&&!!L&&(!o||k&&o);return Object(s.d)("div",{css:O(C)},Object(s.d)("div",{css:h(C)},Object(s.d)(l.a,{variant:"h3bold"},g()("Your grade")),Object(s.d)(l.a,{variant:"h1",component:"div",color:P?"success":"error","data-test":"grade-percent"},Object(s.d)(S,{itemGrade:t,computedScore:n,maxScore:a,reviewsExpected:b,reviewsReceived:v}))),r()(I)&&i&&Object(s.d)("div",{css:f(C)},Object(s.d)(d.a,{variant:c?"ghost":"primary",onClick:i,"data-test":"feedback-button"},g()("View Feedback")),y&&Object(s.d)(l.a,{variant:"body2",color:"supportText"},g()("We keep your highest score"))))},S=function CoverPageRowGradeDetail(e){var t=e.itemGrade,n=e.computedScore,a=e.maxScore,i=e.reviewsExpected,c=void 0===i?0:i,o=e.reviewsReceived,d=void 0===o?0:o,v,O=(t||{}).grade,f=Object(u.a)();if(r()(O))return Object(s.d)("div",{css:Object(s.c)(_templateObject4())},Object(m.b)(O),Object(s.d)(p.a,{itemGrade:t,computedScore:n,maxScore:a}));if(c>0&&d>0)return Object(s.d)(l.a,{variant:"body2"},Object(s.d)(b.b,{message:g()("In progress, {reviewsReceived, number} of {reviewsExpected, number} received"),reviewsExpected:c,reviewsReceived:d}));return Object(s.d)(l.a,{variant:"h1",component:"p",color:"supportText",css:Object(s.c)(_templateObject5(),f.spacing(8,0,0,0)),"data-test":"no-grade-text"},Object(s.d)("span",{"aria-hidden":"true"},"-"),Object(s.d)(j.b,{tagName:"span"},g()("Not available")))};e.a=y},USJv:function(module,e,t){"use strict";var n=t("q1tI"),a=t.n(n),i=t("MnCE"),r=t("oyNZ");function _extends(){return(_extends=Object.assign||function(e){for(var t=1;t<arguments.length;t++){var n=arguments[t];for(var a in n)Object.prototype.hasOwnProperty.call(n,a)&&(e[a]=n[a])}return e}).apply(this,arguments)}function _objectWithoutProperties(e,t){if(null==e)return{};var n=_objectWithoutPropertiesLoose(e,t),a,i;if(Object.getOwnPropertySymbols){var r=Object.getOwnPropertySymbols(e);for(i=0;i<r.length;i++){if(a=r[i],t.indexOf(a)>=0)continue;if(!Object.prototype.propertyIsEnumerable.call(e,a))continue;n[a]=e[a]}}return n}function _objectWithoutPropertiesLoose(e,t){if(null==e)return{};var n={},a=Object.keys(e),i,r;for(r=0;r<a.length;r++){if(i=a[r],t.indexOf(i)>=0)continue;n[i]=e[i]}return n}var c=function SvgaChart(e){var t=e.title,a=void 0===t?"Chart":t,i=_objectWithoutProperties(e,["title"]);return n.createElement(r.a,_extends({title:a},i,{viewBox:"0 0 41 37"}),n.createElement("g",{fill:"none",fillRule:"evenodd"},n.createElement("path",{fill:"#F26C75",d:"M5 32h32V0H5z"}),n.createElement("path",{stroke:"#424242",strokeWidth:"2",d:"M8 28l9.263-12.572 10.105 8.98L40 6"}),n.createElement("path",{stroke:"#4D4D4D",strokeWidth:"2",d:"M1 0v36h40"})))};(c=Object(i.pure)(c)).displayName="SvgaChart",e.a=c},"YdC/":function(module,e,t){"use strict";var n=t("VkAN"),a=t.n(n),i=t("q1tI"),r=t.n(i),c=t("AeFk"),o=t("JJfJ"),s=t("763+"),u=t("8Hdl"),l=t("PB6g");function _templateObject2(){var e=a()(["\n    margin-top: ",";\n    "," {\n      margin-top: ",";\n    }\n  "]);return _templateObject2=function _templateObject2(){return e},e}function _templateObject(){var e=a()(["\n    margin: ",";\n    "," {\n      margin: ",";\n    }\n    "," {\n      margin: ",";\n    }\n  "]);return _templateObject=function _templateObject(){return e},e}var d=function header(e){return Object(c.c)(_templateObject(),e.spacing(32,0),e.breakpoints.up("sm"),e.spacing(48,0,32,0),e.breakpoints.up("md"),e.spacing(48,0))},m=function subHeader(e){return Object(c.c)(_templateObject2(),e.spacing(8),e.breakpoints.up("md"),e.spacing(4))},b=function CoverPageHeader(e){var t=e.assignmentTypeName,n=e.item,a=(n=void 0===n?{}:n).timeCommitment,r=n.name,b=e.subHeader,p=Object(s.a)();return Object(c.d)("div",{css:d(p)},Object(c.d)(u.a,{variant:"d2",component:"h1"},r),Object(c.d)(u.a,{variant:"body2",component:"div",css:m(p)},t,!!a&&Object(c.d)(i.Fragment,null,Object(c.d)(l.b,{tagName:"span"},Object(o.t)(a,!0)),Object(c.d)("span",{"aria-hidden":!0}," • ",Object(o.t)(a)))),b&&Object(c.d)("div",{css:m(p)},b))};e.a=b},fHLu:function(module,e,t){"use strict";t.d(e,"a",function(){return i});var n=t("S0QZ"),a=function clearQuizApolloCache(e){Object(n.a)(e.cache,["RestQuizSessionMetadataElement","RestQuizQuestionDataElement","LocalTimerState","LocalChangedResponse","LocalStepState","$ROOT_QUERY.ChangedResponse"])},i=function clearPracticeQuizApolloCache(e){Object(n.a)(e.cache,["LocalChangedResponse","LocalStepState"])};e.b=a},hgsf:function(module,e,t){"use strict";var n=t("lSNA"),a=t.n(n),i=t("UB5X"),r=t.n(i),c=t("q1tI"),o=t.n(c),s=t("AeFk"),u=t("JJfJ"),l=t("kvW3"),d=t("ryMZ"),m=t("izmZ"),b=t("d3Ej"),p=t.n(b),v=t("763+"),g=function root(e){return Object(s.c)(a()({display:"flex",flexDirection:"column"},e.breakpoints.only("xs"),{flexDirection:"column"}))},j=function row(e){return Object(s.c)(a()({display:"flex",flexDirection:"row",marginBottom:e.spacing(8)},e.breakpoints.only("xs"),{flexDirection:"column",marginBottom:0}))},O=function CoverPageDetails(e){var t=e.deadline,n=e.attemptsCompleted,a=void 0===n?0:n,i=e.attemptsLeft,c=e.attemptsRateCount,o=e.attemptsRateInterval,b=e.passingFraction,O=e.isCumulativeGraded,f=e.lastSubmittedAt,h=Object(v.a)(),y=r()(i)?i+a:null;return Object(s.d)("div",{css:g(h)},Object(s.d)("div",{css:j(h)},t&&Object(s.d)(d.a,{label:p()("Due"),details:Object(u.s)(t,u.g),ariaDetails:Object(u.s)(t,u.b)}),r()(i)&&Object(s.d)(d.a,{label:p()("Attempts"),details:Object(s.d)(l.b,{message:p()("{attemptsLeft, number} left ({attemptsMax, number} total attempts)"),attemptsLeft:Math.max(i,0),attemptsMax:y})}),r()(c)&&r()(o)&&Object(s.d)(d.a,{label:p()("Attempts"),details:Object(s.d)(l.b,{message:p()("{count, number} every {duration}"),count:c,duration:Object(u.t)(o,!0)})}),r()(b)&&!O&&Object(s.d)(d.a,{label:p()("To Pass"),details:Object(s.d)(l.a,{message:p()("{percent} or higher"),percent:Object(s.d)(m.a,{value:b,maxFractionDigits:0})})})),f&&Object(s.d)("div",{css:j(h)},Object(s.d)(d.a,{label:p()("Submitted"),details:Object(u.s)(f,u.g),ariaDetails:Object(u.s)(f,u.b)})))};e.a=O},iMVg:function(module,e,t){"use strict";var n=t("J4zp"),a=t.n(n),i=t("AeFk"),r=t("q1tI"),c=t.n(r),o=t("ZJgU"),s=t("3AF4"),u=t("s3XC"),l=t("mDy0"),d=t("vrZb"),m=t.n(d),b={linkButton:Object(i.c)({marginLeft:-16})},p=function LearningObjectivesButton(e){var t=e.itemId,n=e.courseSlug,c=e.learningObjectiveIds,d=Object(r.useState)(),p=a()(d,2),v=p[0],g=p[1],j=function toggleTunnelVision(){return g(!v)};if(!(null==c?void 0:c.length))return null;return Object(i.d)("div",null,Object(i.d)(o.a,{variant:"ghost",css:b.linkButton,onClick:j,"data-test":"review-button"},m()("Review Learning Objectives")),v&&Object(i.d)(u.b,{"data-test":"tunnel-vision-wrapper",onClose:j,headerLeft:Object(i.d)(s.b,{headerText:m()("Review Learning Objectives"),itemTypeText:m()("Review materials")}),headerRight:Object(i.d)("div",null)},Object(i.d)(l.a,{"data-test":"learning-objectives-content",itemId:t,courseSlug:n,learningObjectiveIds:c})))};e.a=p},jXJP:function(module,e,t){"use strict";var n=t("VkAN"),a=t.n(n),i=t("lSNA"),r=t.n(i),c=t("UB5X"),o=t.n(c),s=t("q1tI"),u=t.n(s),l=t("AeFk"),d=t("ZJgU"),m=t("763+"),b=t("8Hdl"),p=t("H7bS"),v=t("d3Ej"),g=t.n(v),j=t("kWps"),O=t("kvW3"),f=t("JJfJ"),h=t("d2Ft");function _templateObject(){var e=a()(["\n                transform: translateY(4px);\n              "]);return _templateObject=function _templateObject(){return e},e}var y=function styles(e){return{submissionTime:Object(l.c)({marginTop:e.spacing(8),marginBottom:-8}),root:Object(l.c)(r()({},e.breakpoints.down("sm"),{marginTop:e.spacing(12)})),actionButtonStyle:Object(l.c)(r()({display:"flex",justifyContent:"flex-end"},e.breakpoints.down("sm"),{justifyContent:"flex-start"})),retryInfo:Object(l.c)({marginTop:e.spacing(12)}),timeLimitText:Object(l.c)({marginTop:e.spacing(12)})}},S=function renderActionButton(e,t){return Object(l.d)(d.a,{size:"medium",variant:"primary",onClick:t,"aria-labelledby":e,"data-test":"action-button"},e)},w=function CoverPageRowRightSideActions(e){var t=e.startAttempt,n=e.restartAttempt,a=e.resumeAttempt,i=e.retryAttempt,r=e.submissionTime,c=e.showTimer,s=e.timeLimit,u=e.timerId,v=e.attemptsLeft,w=e.secondsLeftInLatestAttempt,k=e.attemptLimitTimeLeft,C=null,x=Object(m.a)(),I=y(x),L=o()(k)||"number"==typeof v&&v<=0;return t?C=S(g()("Start assignment"),t):n?C=S(g()("Restart assignment"),n):a?C=S(g()("Resume assignment"),a):i&&(C=Object(l.d)(d.a,{size:"medium",variant:"ghost","data-test":"action-button","aria-labelledby":g()("Try again"),component:"a",onClick:i,disabled:L},g()("Try again"))),Object(l.d)("div",{css:I.root},Object(l.d)("div",{css:I.actionButtonStyle},C),L&&o()(k)&&Object(l.d)("div",{css:I.retryInfo,"data-test":"retry-info"},Object(l.d)(b.a,{variant:"body2",component:"span",color:"supportText"},Object(l.d)(O.b,{message:g()("Retake the quiz in {attemptLimitTimeLeft}"),attemptLimitTimeLeft:Object(l.d)("strong",null,Object(f.t)(k))}))),r&&Object(l.d)("div",{css:I.submissionTime,"data-test":"submission-time-detail"},Object(l.d)(b.a,{variant:"h4bold",component:"span",color:"supportText"},g()("Submitted"))," ",Object(l.d)(b.a,{variant:"body2",component:"span",color:"supportText"},j.a.getFormattedDeadline(r))),o()(s)&&t&&Object(l.d)("div",null,Object(l.d)(b.a,{variant:"body2"},Object(l.d)(p.a,{size:"medium",color:"default",css:Object(l.c)(_templateObject())}),Object(l.d)("span",{css:I.timeLimitText},Object(l.d)(O.b,{message:g()("You will have {timeLimit} to finish"),timeLimit:Object(f.t)(s,!0)})))),c&&o()(w)&&Object(l.d)(h.a,{timerId:u,remainingTimeInMs:1e3*w,displayRemaining:!0}))};e.a=w},lT6G:function(module,e,t){"use strict";t.r(e),t.d(e,"QuizCoverPage",function(){return F});var n=t("lSNA"),a=t.n(n),i=t("VbXa"),r=t.n(i),c=t("q1tI"),o=t.n(c),s=t("AeFk"),u=t("MnCE"),l=t("oJmH"),d=t.n(l),m=t("sBWo"),b=t("8mOo"),p=t("+LJP"),v=t("fHLu"),g=t("YdC/"),j=t("iMVg"),O=t("pRpZ"),f=t("6/Gu"),h=t("YmkS"),y=t("qJwm"),S=t("2iEy"),w=t("hgsf"),k=t("jXJP"),C=t("NXzb"),x=t("1ah5"),I=t("zaiP"),L=t("LHEl"),P=t("kYu0"),A=t("VtNW"),E=t.n(A),T=t("VMeS"),R=t("8ec0"),N=t("xXQ2"),D=t("KvdX");function ownKeys(e,t){var n=Object.keys(e);if(Object.getOwnPropertySymbols){var a=Object.getOwnPropertySymbols(e);t&&(a=a.filter(function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable})),n.push.apply(n,a)}return n}function _objectSpread(e){for(var t=1;t<arguments.length;t++){var n=null!=arguments[t]?arguments[t]:{};t%2?ownKeys(Object(n),!0).forEach(function(t){a()(e,t,n[t])}):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(n)):ownKeys(Object(n)).forEach(function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(n,t))})}return e}var F=function(e){function QuizCoverPage(){for(var t,n=arguments.length,a=new Array(n),i=0;i<n;i++)a[i]=arguments[i];return(t=e.call.apply(e,[this].concat(a))||this).getRestartAttemptFunction=function(e,n,a){return function(){if(n&&a){if(a.isLastAttemptBeforeLock||1===a.attemptsLeft)return void n({type:D.a.lastAttemptModal,props:_objectSpread(_objectSpread({},a),{},{onPrimaryButtonClick:t.getRestartAttemptFunction(e)})});if("number"==typeof a.timeLimit)return void n({type:D.a.timedAttemptStart,props:_objectSpread(_objectSpread({},a),{},{onPrimaryButtonClick:t.getRestartAttemptFunction(e)})})}var i=t.props.openAttemptPage;Object(v.b)(e),i()}},t}var t;return r()(QuizCoverPage,e),QuizCoverPage.prototype.render=function render(){var e=this,t=this.props,n=t.nextItemUrl,a=t.children,i=t.openSubmittedAttemptPage;return Object(s.d)(I.a,null,function(t){var r=t.item;if(!r||!r.contentSummary)return Object(s.d)(T.a,null);return Object(s.d)(L.a,{courseId:r.courseId,itemId:r.id},function(t){var c=t.loading,u=t.lastSessionId,d=t.lockingConfigurationSummary,m=t.unsubmittedSessionId,b=t.bestEvaluation,p=t.nudge,I=t.refetch;if(!r||!r.contentSummary||c)return Object(s.d)(T.a,null);if("exam"===r.contentSummary.typeName){var L=r.contentSummary.definition,A=r.isCumulativeGraded;return Object(s.d)(f.a,{container:!0},Object(s.d)(f.a,{item:!0,xs:12},Object(s.d)(g.a,{assignmentTypeName:E()("Quiz"),item:r,subHeader:Object(s.d)(j.a,{courseId:null==r?void 0:r.courseId,itemId:null==r?void 0:r.id,courseSlug:null==r?void 0:r.courseSlug,learningObjectiveIds:null==r?void 0:r.learningObjectiveIds})}),p&&Object(s.d)(O.a,{nudge:p})),Object(s.d)(f.a,{item:!0,xs:12},Object(s.d)(x.a,{courseSlug:null==r?void 0:r.courseSlug})),Object(s.d)(f.a,{item:!0,xs:12},Object(s.d)(P.a,{standardProctorConfigurationId:L.standardProctorConfigurationId},function(t){var n=t.timeLimit,a=t.secondsLeftInLatestAttempt,i=t.remainingAttempts,c=t.completedAttempts,o=t.client;return Object(s.d)(S.b,{stepTitle:E()("Submit your assignment"),stepDetails:Object(s.d)(w.a,{deadline:r.deadline,attemptsRateCount:(d||{}).allowedSubmissionsPerInterval,attemptsRateInterval:(d||{}).allowedSubmissionsInterval,attemptsLeft:i,attemptsCompleted:c}),rightSideView:Object(s.d)(D.b,null,function(t){var c=t.showModal,l={timeLimit:n,attemptsLeft:i,lockedTimeLeft:Object(N.b)(d),isLastAttemptBeforeLock:Object(N.c)(d),hasAttemptLimit:!!d&&d.allowedSubmissionsPerInterval>0};return Object(s.d)(k.a,{startAttempt:u||m?void 0:e.getRestartAttemptFunction(o,c,l),resumeAttempt:m?e.getRestartAttemptFunction(o):void 0,timeLimit:n,showTimer:!!m,timerId:Object(R.a)(r.id),secondsLeftInLatestAttempt:a,retryAttempt:e.getRestartAttemptFunction(o,c,l),attemptLimitTimeLeft:Object(N.a)(d),attemptsLeft:i})}),statusIconType:u?S.a.check:void 0,statusIconTitle:u?E()("Activity Completed"):void 0})}),Object(s.d)(S.b,{stepTitle:E()("Receive grade"),stepDetails:Object(s.d)(w.a,{passingFraction:L.passingFraction,isCumulativeGraded:A}),rightSideView:Object(s.d)(l.ApolloConsumer,null,function(e){return Object(s.d)(C.a,{itemGrade:r.itemGrade,computedScore:(b||{}).score,maxScore:(b||{}).maxScore,isCumulativeGraded:A,viewFeedback:u?function(){Object(v.b)(e),i()}:void 0,isViewFeedbackButtonLinkStyle:!!m})}),statusIconType:Object(S.d)((r.itemGrade||{}).isPassed,A),statusIconTitle:Object(S.c)((r.itemGrade||{}).isPassed,A)})),Object(s.d)("div",{css:function css(e){return Object(s.c)({marginTop:e.spacing(12)})}},Object(s.d)(h.a,{computedItem:r,itemFeedbackType:y.c.Quiz})),a&&I&&o.a.cloneElement(a,{refetchCoverPageData:function refetchCoverPageData(){return I().then(function(){return r.refetch()})},nextItemUrl:n}))}return null})})},QuizCoverPage}(o.a.Component),M=Object(u.compose)(b.a,Object(p.a)(function(e){return{openAttemptPage:function openAttemptPage(){e.push({name:"quiz-attempt",params:e.params})},openSubmittedAttemptPage:function openSubmittedAttemptPage(){e.push({name:"quiz-view-attempt",params:e.params})}}}))(F);e.default=Object(m.a)(M)},mDy0:function(module,e,t){"use strict";var n=t("AeFk"),a=t("q1tI"),i=t.n(a),r=t("8Hdl"),c=t("Euzd"),o=t("2S0G"),s=t("vrZb"),u=t.n(s),l={root:function root(e){return Object(n.c)({marginBottom:e.spacing(48)})},instructions:function instructions(e){return Object(n.c)({marginTop:e.spacing(8)})},learningObjectiveContainer:function learningObjectiveContainer(e){return Object(n.c)({marginTop:e.spacing(32)})}},d=function LearningObjectivesContent(e){var t=e.itemId,a=e.courseSlug,i=void 0===a?"":a,s=e.learningObjectiveIds;return Object(n.d)("div",{css:l.root},Object(n.d)(r.a,{variant:"h1semibold",component:"h2"},u()("Review Learning Objectives")),Object(n.d)(r.a,{variant:"body2",css:l.instructions},u()("Review concepts related to your current learning objectives")),Object(n.d)("div",{css:l.learningObjectiveContainer},Object(n.d)(c.a,{itemId:t,courseSlug:i,learningObjectiveIds:s,removeParentItem:!0,removeFutureItems:!0},function(e){var t=e.learningObjectives;return Object(n.d)(o.a,{learningObjectives:t})})))};e.a=d},oX1x:function(module,e,t){"use strict";var n=t("VkAN"),a=t.n(n),i=t("q1tI"),r=t.n(i),c=t("sQ/U"),o=t("PDuk"),s=t("lTCR"),u=t.n(s),l=t("oJmH"),d=t.n(l),m=t("iC89");function _templateObject(){var e=a()(["\n  query CourseMessagesQuery($id: String!) {\n    CourseMessagesV1 @naptime {\n      findCourseMessages(id: $id) {\n        elements {\n          id\n          messages\n        }\n      }\n    }\n  }\n"]);return _templateObject=function _templateObject(){return e},e}var b=u()(_templateObject()),p=function CourseMessagesProvider(e){var t=e.courseSlug,n=e.children,a=c.a.get().id,i=Object(o.c)([Object(o.c)([a,t]),m.a.COURSE_GRADES,-1]);return r.a.createElement(l.Query,{query:b,variables:{id:i}},function(e){var t,a,i,r=e.loading,c=e.data,o=e.refetch,s=null==c?void 0:null===(t=c.CourseMessagesV1)||void 0===t?void 0:null===(a=t.findCourseMessages)||void 0===a?void 0:null===(i=a.elements)||void 0===i?void 0:i[0].messages;return n({loading:r,notifications:s,refetch:o})})};e.a=p},pRpZ:function(module,e,t){"use strict";var n=t("q1tI"),a=t.n(n),i=t("EqTq"),r=t("w+/x"),c=t("USJv"),o=t("m10x"),s=t("kvW3"),u=t("d3Ej"),l=t.n(u),d=t("FkXZ"),m=t.n(d),b=Object(i.a)("CoverPageNudges"),p=function LikelihoodNudge(e){var t=e.value,n=Math.ceil(t/100);return a.a.createElement("div",{className:b()},a.a.createElement("div",{className:b("svg-icon")},a.a.createElement(c.a,{size:48})),a.a.createElement("div",{className:b("message")},a.a.createElement(o.n,null,l()("Get closer to your goal")),a.a.createElement(s.b,{message:l()("You are {value} more likely to complete the course if you finish the assignment"),value:a.a.createElement("strong",null,n>1?n+l()(" times"):t+"%"),tagName:"p",rootClassName:b("info")})))},v=function SocialNudge(e){var t=e.value;return a.a.createElement("div",{className:b()},a.a.createElement("div",{className:b("svg-icon")},a.a.createElement(r.a,{size:48}),","),a.a.createElement("div",{className:b("message")},a.a.createElement(o.n,null,l()("People are making progress")),a.a.createElement(s.b,{message:l()("{numOfLearners} learners have recently completed this assignment"),numOfLearners:a.a.createElement("strong",null,t),tagName:"p",rootClassName:b("info")})))},g=function CoverPageNudges(e){var t=e.nudge,n=t.nudgeType,i=t.nudgeNumber;switch(n){case"social":return a.a.createElement(v,{value:i});case"likelihood":return a.a.createElement(p,{value:i});default:return null}};e.a=g},ryMZ:function(module,e,t){"use strict";var n=t("lSNA"),a=t.n(n),i=t("q1tI"),r=t.n(i),c=t("AeFk"),o=t("763+"),s=t("8Hdl"),u=t("PB6g"),l=function root(e){return Object(c.c)({whiteSpace:"nowrap","& + &":a()({marginLeft:e.spacing(16)},e.breakpoints.down("xs"),{marginLeft:0})})},d=function label(e){return Object(c.c)({marginRight:e.spacing(8)})},m=function CoverPagePhaseDetail(e){var t=e.label,n=e.details,a=e.ariaDetails,i=Object(o.a)();return Object(c.d)("div",{css:l(i)},Object(c.d)(s.a,{variant:"h4bold",component:"span",css:d(i),color:"supportText","data-test":"label"},t)," ",Object(c.d)(s.a,{variant:"body2",component:"span",color:"supportText","data-test":"content"},a&&Object(c.d)(u.b,{tagName:"span"},a),Object(c.d)("span",{"aria-hidden":Boolean(a)},n)))};e.a=m},"w+/x":function(module,e,t){"use strict";var n=t("q1tI"),a=t.n(n),i=t("MnCE"),r=t("oyNZ");function _extends(){return(_extends=Object.assign||function(e){for(var t=1;t<arguments.length;t++){var n=arguments[t];for(var a in n)Object.prototype.hasOwnProperty.call(n,a)&&(e[a]=n[a])}return e}).apply(this,arguments)}function _objectWithoutProperties(e,t){if(null==e)return{};var n=_objectWithoutPropertiesLoose(e,t),a,i;if(Object.getOwnPropertySymbols){var r=Object.getOwnPropertySymbols(e);for(i=0;i<r.length;i++){if(a=r[i],t.indexOf(a)>=0)continue;if(!Object.prototype.propertyIsEnumerable.call(e,a))continue;n[a]=e[a]}}return n}function _objectWithoutPropertiesLoose(e,t){if(null==e)return{};var n={},a=Object.keys(e),i,r;for(r=0;r<a.length;r++){if(i=a[r],t.indexOf(i)>=0)continue;n[i]=e[i]}return n}var c=function SvgaPen(e){var t=e.title,a=void 0===t?"Pen":t,i=_objectWithoutProperties(e,["title"]);return n.createElement(r.a,_extends({title:a},i,{viewBox:"0 0 36 44"}),n.createElement("g",{fill:"none",fillRule:"evenodd"},n.createElement("path",{d:"M36 25.855C36 35.845 20.836 44 10.895 44S0 35.846 0 25.855C0 15.865 13.185 8 23.127 8 33.067 8 36 15.864 36 25.855",fill:"#F3C800"}),n.createElement("path",{stroke:"#4D4D4D",strokeWidth:"2",strokeLinecap:"round",strokeLinejoin:"round",d:"M21.907 4.781l6.751 12.248-10.823 17.146L7.253 17.181l6.999-12.452M8.428 4.081h19.359V1H8.427zM17.954 33.074V21.186"}),n.createElement("path",{d:"M15.23 18.272a2.723 2.723 0 1 1 5.447 0 2.723 2.723 0 0 1-5.446 0z",stroke:"#4D4D4D",strokeWidth:"2",strokeLinecap:"round",strokeLinejoin:"round"})))};(c=Object(i.pure)(c)).displayName="SvgaPen",e.a=c}}]);
//# sourceMappingURL=97.b4c6da5576244527b2ac.js.map