package com.company;
import junit.framework.TestCase;

import java.util.Scanner;





import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class Main extends TestCase {


    public Main(String testName) {
        super(testName);
    }

    // custom assert to test manual testing section
    public static void myAssert (boolean bool1, boolean bool2, String url){
        if(bool1 == bool2)
            System.out.println(url + " is Valid");
        else
            System.out.println("ERROR: " + url + " is Invalid");
    }


    // custom assert to test programming testing section
    public static void myAssert2(boolean bool1, boolean bool2, String url){
        if(bool1 =! bool2)
            System.out.println("ERROR: " + url + " didn't match expected isValid() return");
    }



    // Manual Testing tests the isValid() function against known valid and invalid URLs
    public static void testManualTest() {
        System.out.println("Running testManualTest()");
        UrlValidator urlVal = new UrlValidator();

        // tests should evaluate to true
        System.out.println("The following URLs should evaluate to true:");
        myAssert(true, urlVal.isValid("http://www.google.com"), "http://www.google.com");
        myAssert(true, urlVal.isValid("https://www.facebook.com"), "https://www.facebook.com");
        myAssert(true, urlVal.isValid("h3t://255.255.255.255/test1/file"), "h3t://255.255.255.255/test1/file");
        myAssert(true, urlVal.isValid("http://www.google.com/index.html"), "http://www.google.com/index.html");
        myAssert(true, urlVal.isValid("http://www.google.com/index.html"), "http://www.google.com:80/test/index.html");
        System.out.println("Done with true URLs\n");

        // tests should evaluate to false
        System.out.println("The following URLs should evaluate to false:");
        myAssert(false, urlVal.isValid("www.google.com"), "www.google.com");	// Should fail because no scheme
        myAssert(false, urlVal.isValid("ʘ"), "ʘ");	// Should fail because Non-ASCII - Bilabial click
        myAssert(false, urlVal.isValid("Җ"), "Җ");	// Should fail because Non-ASCII - Zhje
        myAssert(false, urlVal.isValid(null), "NULL string"); // Should fail because not a string
        myAssert(false, urlVal.isValid("http://google.com///test1"), "http://google.com///test1"); // Should fail because ///
        System.out.println("Done with false URLs");
        System.out.println("testManualTest() Complete\n");
    }




    //You can use this function to implement your First Partition testing
    public static void testYourFirstPartition(){
        //First partition is that the scheme remains the same while the others change
        UrlValidator urlVal = new UrlValidator();

        System.out.println("Scheme partition testing URLs made from ResultPair Objects, scheme is true:");

        ResultPair goodScheme = new ResultPair("http://", true);
        ResultPair goodAuthority = new ResultPair("www.google.com", true);
        ResultPair goodPort = new ResultPair(":8888", true);
        ResultPair goodPath = new ResultPair("", true);
        ResultPair goodQuery = new ResultPair("", true);

        ResultPair badScheme = new ResultPair("http:", false);
        ResultPair badAuthority = new ResultPair("aaa.", false);
        ResultPair badPort = new ResultPair(":-1", false);
        ResultPair badPath = new ResultPair("/../", false);

        String schemeTrueOthersTrue = goodScheme.item + goodAuthority.item + goodPort.item + goodPath.item + goodQuery.item;
        myAssert(true, urlVal.isValid(schemeTrueOthersTrue), schemeTrueOthersTrue);

        String schemeTrueOthersFalse = goodScheme.item + badAuthority.item + badPort.item + badPath.item;
        myAssert(false, urlVal.isValid(schemeTrueOthersFalse), schemeTrueOthersFalse);

        System.out.println("Scheme partition testing URLs made from ResultPair Objects, scheme is false:");

        String schemeFalseOthersTrue = badScheme.item + goodAuthority.item + goodPort.item + goodPath.item + goodQuery.item;
        myAssert(false, urlVal.isValid(schemeFalseOthersTrue), schemeFalseOthersTrue);

        String schemeFalseOthersFalse = badScheme.item + badAuthority.item + badPort.item + badPath.item;
        myAssert(false, urlVal.isValid(schemeFalseOthersFalse), schemeFalseOthersFalse);
    }


    //You can use this function to implement your Second Partition testing
    public static void testYourSecondPartition(){
        //Second partition is that the Authority remains the same while the others change
        UrlValidator urlVal = new UrlValidator();

        System.out.println("Authority partition testing URLs made from ResultPair Objects, Authority is true:");

        ResultPair goodScheme = new ResultPair("http://", true);
        ResultPair goodAuthority = new ResultPair("www.google.com", true);
        ResultPair goodPort = new ResultPair(":8888", true);
        ResultPair goodPath = new ResultPair("", true);
        ResultPair goodQuery = new ResultPair("", true);

        ResultPair badScheme = new ResultPair("http:", false);
        ResultPair badAuthority = new ResultPair("aaa.", false);
        ResultPair badPort = new ResultPair(":-1", false);
        ResultPair badPath = new ResultPair("/../", false);

        String authorityTrueOthersTrue = goodScheme.item + goodAuthority.item + goodPort.item + goodPath.item + goodQuery.item;
        myAssert(true, urlVal.isValid(authorityTrueOthersTrue), authorityTrueOthersTrue);

        String authorityTrueOthersFalse = badScheme.item + goodAuthority.item + badPort.item + badPath.item;
        myAssert(false, urlVal.isValid(authorityTrueOthersFalse), authorityTrueOthersFalse);

        System.out.println("Authority partition testing URLs made from ResultPair Objects, Authority is false:");

        String authorityFalseOthersTrue = goodScheme.item + badAuthority.item + goodPort.item + goodPath.item + goodQuery.item;
        myAssert(false, urlVal.isValid(authorityFalseOthersTrue), authorityFalseOthersTrue);

        String authorityFalseOthersFalse = badScheme.item + badAuthority.item + badPort.item + badPath.item;
        myAssert(false, urlVal.isValid(authorityFalseOthersFalse), authorityFalseOthersFalse);

    }


    public static void testYourThirdPartition(){
        //Third partition is that the Port remains the same while the others change
        UrlValidator urlVal = new UrlValidator();

        System.out.println("Port partition testing URLs made from ResultPair Objects, Port is true:");

        ResultPair goodScheme = new ResultPair("http://", true);
        ResultPair goodAuthority = new ResultPair("www.google.com", true);
        ResultPair goodPort = new ResultPair(":8888", true);
        ResultPair goodPath = new ResultPair("", true);
        ResultPair goodQuery = new ResultPair("", true);

        ResultPair badScheme = new ResultPair("http:", false);
        ResultPair badAuthority = new ResultPair("aaa.", false);
        ResultPair badPort = new ResultPair(":-1", false);
        ResultPair badPath = new ResultPair("/../", false);

        String portTrueOthersTrue = goodScheme.item + goodAuthority.item + goodPort.item + goodPath.item + goodQuery.item;
        myAssert(true, urlVal.isValid(portTrueOthersTrue), portTrueOthersTrue);

        String portTrueOthersFalse = badScheme.item + badAuthority.item + goodPort.item + badPath.item;
        myAssert(false, urlVal.isValid(portTrueOthersFalse), portTrueOthersFalse);

        System.out.println("Port partition testing URLs made from ResultPair Objects, Port is false:");

        String portFalseOthersTrue = goodScheme.item + goodAuthority.item + badPort.item + goodPath.item + goodQuery.item;
        myAssert(false, urlVal.isValid(portFalseOthersTrue), portFalseOthersTrue);

        String portFalseOthersFalse = badScheme.item + badAuthority.item + badPort.item + badPath.item;
        myAssert(false, urlVal.isValid(portFalseOthersFalse), portFalseOthersFalse);

    }

    public static void testYourFourthPartition(){
        //Fourth partition is that the Path remains the same while the others change
        UrlValidator urlVal = new UrlValidator();

        System.out.println("Path partition testing URLs made from ResultPair Objects, Path is true:");

        ResultPair goodScheme = new ResultPair("http://", true);
        ResultPair goodAuthority = new ResultPair("www.google.com", true);
        ResultPair goodPort = new ResultPair(":8888", true);
        ResultPair goodPath = new ResultPair("", true);
        ResultPair goodQuery = new ResultPair("", true);

        ResultPair badScheme = new ResultPair("http:", false);
        ResultPair badAuthority = new ResultPair("aaa.", false);
        ResultPair badPort = new ResultPair(":-1", false);
        ResultPair badPath = new ResultPair("/../", false);

        String pathTrueOthersTrue = goodScheme.item + goodAuthority.item + goodPort.item + goodPath.item + goodQuery.item;
        myAssert(true, urlVal.isValid(pathTrueOthersTrue), pathTrueOthersTrue);

        String pathTrueOthersFalse = badScheme.item + badAuthority.item + badPort.item + goodPath.item;
        myAssert(false, urlVal.isValid(pathTrueOthersFalse), pathTrueOthersFalse);

        System.out.println("Path partition testing URLs made from ResultPair Objects, Path is false:");

        String pathFalseOthersTrue = goodScheme.item + goodAuthority.item + goodPort.item + badPath.item + goodQuery.item;
        myAssert(false, urlVal.isValid(pathFalseOthersTrue), pathFalseOthersTrue);

        String pathFalseOthersFalse = badScheme.item + badAuthority.item + badPort.item + badPath.item;
        myAssert(false, urlVal.isValid(pathFalseOthersFalse), pathFalseOthersFalse);

    }


    // tests the concatenated complete URL parts vs the expected bool
    public static void testURLs(String[] schemes, String[] authorities, String[] parts, String[] paths, String[] queries, boolean valid){

        UrlValidator urlVal = new UrlValidator();

        for (String scheme : schemes){
            for (String authority : authorities){
                for (String port : parts){
                    for (String path : paths){
                        for (String query : queries){

                            String completeURL = scheme + authority + port + path + query;

                            myAssert2(valid, urlVal.isValid(completeURL), completeURL.toString());
                        }
                    }
                }
            }
        }
    }



    // Covers 5 different tests
    // The first test uses all valid parts of a complete URL with each evaluating to true
    // The 4 remaining test each use 4 valid parts of a complete URL with different invalid part
    // for each of the 4 tests. Each of these 4 tests should evaluate to false.
    public static void testIsValid() {
        System.out.println("Running testIsValid()");

        final String[] validSchemes = new String[] {"http://", "ftp://", "h3t://", "https://", ""};
        final String[] invalidSchemes = new String[] {"3ht://", "http:/", "http:", "http/", "://"};
        final String[] validAuthorities = new String[] {"www.google.com", "go.com", "go.au", "0.0.0.0", "255.255.255.255", "255.com", };
        final String[] invalidAuthorities = new String[] {"256.256.256.256", "1.2.3.4.5", "1.2.3.4.", "1.2.3", ".1.2.3.4", "go.a", "go.a1a", "go.1aa", "aaa.", ".aaa", "aaa", ""};
        final String[] validPorts = new String[] {":80", ":65555", ":0", ""};
        final String[] invalidPorts = new String[] {":-1", ":65636", ":65a"};
        final String[] validPaths = new String[] {"/test1", "/t123", "/$23", "/test1/", "/test1/file", ""};
        final String[] invalidPaths = new String[] {"/..", "/../", "/..//file", "/test1//file"};
        final String[] validQueries = new String[] {"?action=view",  "?action=edit&mode=up", ""};

        // testing URLs with all valid complete URL parts
        System.out.println("The following URLs should evaluate to true:");
        testURLs(validSchemes, validAuthorities, validPorts, validPaths, validQueries, true);
        System.out.println("Done with valid URLs\n");


        // testing URLs with invalid schemes
        System.out.println("The following URLs should evaluate to false:");
        System.out.println("Testing URLs with invalid schemes");
        testURLs(invalidSchemes, validAuthorities, validPorts, validPaths, validQueries, false);
        System.out.println("Done with invalid schemes\n");

        // testing URLs with invalid authorities
        System.out.println("Testing URLs with invalid authorities");
        testURLs(validSchemes, invalidAuthorities, validPorts, validPaths, validQueries, false);
        System.out.println("Done with invalid authorities\n");

        // testing URLs with invalid ports
        System.out.println("Testing URLs with invalid ports");
        testURLs(validSchemes, validAuthorities, invalidPorts, validPaths, validQueries, false);
        System.out.println("Done with invalid ports\n");

        // testing URLs with invalid paths
        System.out.println("Testing URLs with invalid paths");
        testURLs(validSchemes, validAuthorities, validPorts, invalidPaths, validQueries, false);
        System.out.println("Done with invalid paths\n");


        // there aren't any invalid queries...

    }




    public static void main(String[] argv) {

        // run our tests
        testManualTest();
        testYourFirstPartition();
        testYourSecondPartition();
        testYourThirdPartition();
        testYourFourthPartition();
        testIsValid();
    }

}
